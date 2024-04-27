#include <iostream>

using namespace std;

template <typename T>
class Queue {

private:
  struct Item {
    T value;
    Item *next;
  };

  Item *first;
  Item *last;
  int _size;
  Queue* q_entangled;

  // Afegeix el que calgui per a poder recordar si la cua està engangled i amb qui.
    
    
  void copyItems(const Item *item, Item *(&first), Item *(&last), int &_size)
  {
    if (item == NULL) {
      first = NULL;
      last = NULL;
      _size = 0;
      return;
    }
    first = new Item();
    first->value = item->value;
    last = first;
    _size = 1;
    while (item->next != NULL) {
      last->next = new Item();
      last = last->next;
      item = item->next;
      last->value = item->value;
      _size++;
    }
    last->next = NULL;
  }


  void deleteItems(Item *item) {
    while (item != NULL) {
      Item *aux = item;
      item = item->next;
      delete aux;
    }
  }
  
public:

  Queue() {
    // Afegeix les inicialitzacions dels nous atributs.
    first = last = NULL;
    _size = 0;
    q_entangled = NULL;
  }

  Queue(const Queue &q)
  {
    copyItems(q.first, first, last, _size);
    // Aquesta funció no es farà servir a l'exercici, però també podeu afegir inicialitzacions aquí si voleu.
  }

  ~Queue() {
    deleteItems(first);
    _size = 0;
  }

  Queue &operator=(const Queue &q) {
    // Aquesta funció no es farà servir a l'exercici, però podeu afegir inicialitzacions si voleu.
    if (this != &q) {
      deleteItems(first);
      copyItems(q.first, first, last, _size);
    }
    return *this;
  }

  T front() {
    if (first == NULL) {
      cerr << "Error: front on empty queue" << endl;
      exit(0);
    }
    return first->value;
  }

  void pop() {
    // Modifica el que calqui per tal que, si la cua està entangled, l'element extret
    // s'afegeixi al final de l'altra cua.
    if (first == NULL) {
      cerr << "Error: pop on empty queue" << endl;
      exit(0);
    }
    Item *aux = first;
    first = first-> next;
    if(q_entangled == NULL) {
        delete aux;
    }
    else{
      aux->next = NULL;
      if(q_entangled->last != NULL) q_entangled->last->next = aux;
      else q_entangled->first = aux;
      q_entangled->last = aux;
      ++q_entangled->_size;
    }
    _size--;
    if (first == NULL) last = NULL;
  }

  void push(T value) {
    Item *pitem = new Item();
    pitem->value = value;
    pitem->next = NULL;
    if (first == NULL) {
      first = last = pitem;
      _size = 1;
      return;
    }
    last->next = pitem;
    last = pitem;
    _size++;
  }

  int size() {
    return _size;
  }

  template<typename U> friend ostream &operator<<(ostream &os, Queue<U> &q);

  template<typename U> friend istream &operator>>(istream &is, Queue<U> &q);

  // Descomenteu i implementeu els següents dos mètodes:

  // Pre:
  // Post: El parámetre implícit queda enllaçat a la cua q que es rep com a paràmetre,
  //       de manera que qualsevol pop sobre el paràmetre implícit afegeix l'element
  //       al final de q. Qualsevol altre entanglement anterior queda cancel.lat.
  void entangle(Queue &q) {
    q_entangled = &q;
  }

  // Pre: El paràmetre implícit està enllaçat a una altra cua.
  // Post: El paràmetre implícit queda desenllaçat, de manera que a partir d'aquest moment
  //       els pops sobre el paràmetre implícit ja no afecten a cap altra cua.
  void disentangle() {
    q_entangled = NULL;
  }

};


template<typename U>
ostream &operator<<(ostream &os, Queue<U> &q)
{
  os << q._size;
  for (typename Queue<U>::Item *item = q.first; item != NULL; item = item->next)
    os << " " << item->value;
  return os;
}

template<typename U>
istream &operator>>(istream &is, Queue<U> &q)
{
  int size;
  is >> size;
  if (size == 0) {
    q = Queue<U> ();
    return is;
  }
  for (int i = 0; i < size; ++i) {
    U x;
    cin >> x;
    q.push(x);
  }
  return is;
}
