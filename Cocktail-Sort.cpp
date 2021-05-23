#include <iostream> 
#include <cstdlib>
#include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

using namespace std;

//ordenar crescente
void CocktailSort(int a[], int n){
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped){
		swapped = false;

		for (int i = start; i < end; ++i)
		{
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;
		--end;
		
		for (int i = end - 1; i >= start; --i){
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		++start;
	}
}

//Método para ordenar decrescente
void CocktailSortDec(int a[], int n){
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped){
		swapped = false;
		for (int i = end; i >= start; --i){
			if (a[i] < a[i + 1]) {
				swap(a[i], a[i+1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;
		--end;

		for (int i = start; i < end; ++i){
			if (a[i] < a[i + 1]) {
				swap(a[i], a[i+1]);
				swapped = true;
			}
		}
		++start;
	}
}

//ordenar de forma crescente ate deteminada posicao do vetor - parcial
void CocktailSort3(int a[], int n, int p_final){
	bool swapped = true;
	int start = 0;
	int end = p_final;

	while (swapped){
		swapped = false;

		for (int i = start; i < end; ++i)
		{
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;
		--end;

		for (int i = end - 1; i >= start; --i){
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		++start;
	}
}

//Método para ordenar decrescente ate determinada posicao do vetor - parcial
void CocktailSortDec3(int a[], int n, int position){
	bool swapped = true;
	int start = position;
	int end = n - 1;

	while (swapped){
		swapped = false;
		for (int i = end; i >= start; --i){
			if (a[i] < a[i + 1]) {
				swap(a[i], a[i+1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;
		--end;

		for (int i = start; i < end; ++i){
			if (a[i] < a[i + 1]) {
				swap(a[i], a[i+1]);
				swapped = true;
			}
		}
		++start;
	}
}

// Classifica array a [0..n-1] usando Cocktail sort crescente
//p_inicial serve para marcar o inicio da metade pro fim do vertor

void CocktailSort4(int a[], int n, int p_inicial){
	bool swapped = true;
	int start = p_inicial;
	int end = n - 1;

	while (swapped)	{
		swapped = false;
		for (int i = start; i < end; ++i){
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;

		swapped = false;
		--end;

		for (int i = end - 1; i >= start; --i){
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		++start;
	}
}

//ordenar vetor de forma decrescente ate certa parte do vetor - parcial
void CocktailSortDec4(int a[], int p_final){
	bool swapped = true;
	int start = 0;
	int end = p_final;

	while (swapped){
		swapped = false;
		for (int i = end; i >= start; --i){
			if (a[i] < a[i + 1]) {
				swap(a[i], a[i+1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;

		swapped = false;
		--end;

		for (int i = start; i < end; ++i){
		
			if (a[i] < a[i + 1]) {
				swap(a[i], a[i+1]);
				swapped = true;
			}
		}
	
		++start;
	}
}

//Primeira metade crescente e segunda metade decrescente
void CocktailSortCresDec(int a[], int n){
	int end = n -1;
	int pos = n/2 -1; 
	
	CocktailSort3(a, 0, pos);	
	CocktailSortDec3(a, n, pos+1);
}

//Primeira metade decrescente e segunda metade crescente 
void CocktailSortDecCres(int a[], int n){
	int end = n -1;	int pos = n/2 -1; 
	CocktailSortDec4(a, pos);
	CocktailSort4(a, n, pos+1);
}

/* Prints dos array */
void printArray(int a[], int n){
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	cout <<"--------------" << endl;
}

int main(){
	
    clock_t t, t2 ,t3, t4, t5; // variável para armazenar o tempo
	int a[100000], v1[100000], v2[100000], v3[100000], v4[100000];
	int n = sizeof(a) / sizeof(a[0]);
	
	t = clock();
	for(int i=0 ; i<n ; i++) a[i] = rand(); //valor randomico
	cout << endl;
	CocktailSortDec(a, n); //CONFIG.1
	
	t2 = clock();
	for(int i=0; i<n; i++)	v1[i] = a[i];	
	CocktailSort(v1, n);  //CONFIG. 2
	
	t3 = clock();
	for(int i=0; i<n; i++)	v2[i] = v1[i];
	CocktailSortCresDec(v2,n); //CONFIG. 3
	
	t4 = clock();
	for(int i=0; i<n; i++)	v3[i] = v2[i]; 	
	CocktailSortDecCres(v3,n); //CONFIG. 4
	
	t5 = clock() ;
	for(int i=0; i<n; i++)	v4[i] = v3[i];
	CocktailSort(v4, n);  //CONFIG. 5
	
	t = clock() - t; 
	t2 = clock() - t2; 
	t3 = clock() - t3; 
	t4 = clock() - t4; 
	t5 = clock() - t5;

	printf("01 - Tempo de execucao: %1f ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	printf("02 - Tempo de execucao: %1f ms\n", ((double)t2)/((CLOCKS_PER_SEC/1000)));
	printf("03 - Tempo de execucao: %1f ms\n", ((double)t3)/((CLOCKS_PER_SEC/1000)));
	printf("04 - Tempo de execucao: %1f ms\n", ((double)t4)/((CLOCKS_PER_SEC/1000)));
	printf("05 - Tempo de execucao: %1f ms\n", ((double)t5)/((CLOCKS_PER_SEC/1000)));
	
	return 0;
}
