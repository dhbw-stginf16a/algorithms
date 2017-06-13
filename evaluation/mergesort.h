extern int MERGE_DATA_COMPS;
extern int MERGE_INDEX_COMPS;
extern int MERGE_ACCESSES;

void mergesort(int a[], int low, int high, int aux);
void recursiveMergesort(int a[], int len);
void merge(int a[], int low, int mid, int high, int aux[]);
void sort(int a[], int low, int high, int aux[]);
