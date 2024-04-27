#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Image {
    string name;
    int depth;
    int i, j;
    vector<string> v;
};

typedef vector<Image> ListImages;

Image readImage() {
    Image img;
    int n, m;
    cin >> img.name >> img.depth >> img.i >> img.j >> n >> m;
    img.v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> img.v[i];
    return img;
}

void computeMinimumBoardDimensions(const ListImages &listimages, int &N, int &M) {
    N = M = 0;
    for (const Image &img : listimages) {
        N = max(N, img.i + int(img.v.size()));
        M = max(M, img.j + int(img.v[0].size()));
    }
}

void drawImage(const Image &image, vector<string> &board) {
    for (int i = 0; i < int(image.v.size()); ++i)
        for (int j = 0; j < int(image.v[i].size()); ++j)
            if (image.v[i][j] != '.')
                board[image.i + i][image.j + j] = image.v[i][j];
}

bool compareImages(const Image& image1, const Image& image2) {
    if (image1.depth != image2.depth)
        return image1.depth > image2.depth;
    return image1.name < image2.name;
}

void drawListImages(ListImages &listimages) {
    sort(listimages.begin(), listimages.end(), compareImages);
    int N, M;
    computeMinimumBoardDimensions(listimages, N, M);
    vector<string> board(N, string(M, '.'));
    for (int i = 0; i < int(listimages.size()); i++)
        drawImage(listimages[i], board);
    for (int i = 0; i < N; i++)
        cout << board[i] << endl;
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    ListImages listimages(n);
    for (int i = 0; i < n; i++) listimages[i] = readImage();
    drawListImages(listimages);
}