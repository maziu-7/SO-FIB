all: proc_time nproc_time nproc_time_max max_5sec nproc_time_max2

proc_time: proc_time.c
	gcc -o proc_time proc_time.c

nproc_time: nproc_time.c
	gcc -o nproc_time nproc_time.c

nproc_time_max: nproc_time_max.c
	gcc -o nproc_time_max nproc_time_max.c

max_5sec: max_5sec.c
	gcc -o max_5sec max_5sec.c

nproc_time_max2: nproc_time_max2.c
	gcc -o nproc_time_max2 nproc_time_max2.c

clean:
	rm -f proc_time nproc_time nproc_time_max nproc_time_max2 max_5sec