#include <iostream>
using namespace std;
double* gauss(double** a, double* y, int n)
{
  int b, k;  
  double* x, m;
  const double e = 0.00001;
  x = new double[n];
  k = 0;
  while (k < n)
  {
    m = abs(a[k][k]);
    b = k;
    for (int i = k + 1; i < n; i++)
    {
      if (abs(a[i][k]) > m)
      {
        m = abs(a[i][k]);
        b = i;
      }
    }
    if (m < e)
    {
      cout << "Решение получить невозможно из-за нулевого столбца ";
      return 0;
    }
    for (int j = 0; j < n; j++)
    {
      double c = a[k][j];
      a[k][j] = a[b][j];
      a[b][j] = c;
    }
    double c = y[k];
    y[k] = y[b];
    y[b] = c;
    for (int i = k; i < n; i++)
    {
      double c = a[i][k];
      if (abs(c) < e) continue;
      for (int j = k; j < n; j++)
        a[i][j] = a[i][j] / c;
      y[i] = y[i] / c;
      if (i == k)  continue;
      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] - a[k][j];
      y[i] = y[i] - y[k];
    }
    k++;
  }
  for (k = n - 1; k >= 0; k--)
  {
    x[k] = y[k];
    for (int i = 0; i < k; i++)
      y[i] = y[i] - a[i][k] * x[k];
  }
  return x;
}
int main()
{
  double** a, * y, * x;
  int n;
  cout << "Введите количество уравнений: ";
  cin >> n;
  a = new double* [n];
  y = new double[n];
  for (int i = 0; i < n; i++)
  {
    a[i] = new double[n];
    for (int j = 0; j < n; j++)
    {
      cout << "x[" << i << "][" << j << "]= ";
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << "x[" << i << "]= ";
    cin >> y[i];
  }
  x = gauss(a, y, n);
  for (int i = 0; i < n; i++){
    cout << "Решения" << endl;
    cout << "x" << i << "=" << x[i] << endl;
  }
  for (int i = 0; i < n; i++)
    delete[] a[i];
  delete[] a;
  delete[] y;
  delete[] x;
  return 0;
}