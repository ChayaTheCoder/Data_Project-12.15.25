#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EPSILON 0.0001

float findMin(float arr[], int size);
float findMax(float arr[], int size);
float calculateAverage(float arr[], int size);
int findIndexOf(float arr[], int size, float num);
int countOccurrences(float arr[], int size, float num);
void printFirst100(float arr[]);
float calculateMedian(float arr[], int size);
float calculateMode(float arr[], int size);
float calculateRange(float arr[], int size);
float calculateVariance(float arr[], int size, float mean);
float calculateStandardDeviation(float arr[], int size, float mean);
void sortArray(float arr[], int size);

int main() {
  float balance[1000];
  int size = 1000;
  int choice = 0;

  srand((unsigned int)time(NULL));
  for (int i = 0; i < size; i++) {
    balance[i] = ((float)rand() / (float)(RAND_MAX)) * 100.0;
  }

  while (choice != 13) {
    printf("\nWelcome to the Data Explorer: Building Essential Data Analysis "
           "Tools in C!\n");
    printf("Please choose an option by entering the corresponding number:\n");
    printf("1: Find the minimum value\n");
    printf("2: Find the maximum value\n");
    printf("3: Calculate the average\n");
    printf("4: Find the index of a given number\n");
    printf("5: Count occurrences of a given number\n");
    printf("6: Print the first 100 elements\n");
    printf("7: Calculate the median\n");
    printf("8: Calculate the mode\n");
    printf("9: Calculate the range\n");
    printf("10: Calculate the variance\n");
    printf("11: Calculate the standard deviation\n");
    printf("12: Sort the array\n");
    printf("13: Exit\n");
    printf("Enter your command: ");
    scanf("%d", &choice);
    printf("\n");

    if (choice == 1) {
      float min = findMin(balance, size);
      printf("The minimum value is: %.2f\n", min);
    } else if (choice == 2) {
      float max = findMax(balance, size);
      printf("The maximum value is: %.2f\n", max);
    } else if (choice == 3) {
      float avg = calculateAverage(balance, size);
      printf("The average value is: %.2f\n", avg);
    } else if (choice == 4) {
      float num;
      printf("Enter the number to find: ");
      scanf("%f", &num);
      int index = findIndexOf(balance, size, num);
      if (index != -1)
        printf("The number %.2f found at index: %d\n", num, index);
      else
        printf("The number %f is not found in the array.\n", num);
    } else if (choice == 5) {
      float num;
      printf("Enter the number to count: ");
      scanf("%f", &num);
      int count = countOccurrences(balance, size, num);
      printf("The number %.2f occurs %d times in the array.\n", num, count);
    } else if (choice == 6) {
      printf("First 100 elements of the array:\n");
      printFirst100(balance);
    } else if (choice == 7) {
      float median = calculateMedian(balance, size);
      printf("The median is: %.2f\n", median);
    } else if (choice == 8) {
      float mode = calculateMode(balance, size);
      printf("The mode is: %.2f\n", mode);
    } else if (choice == 9) {
      float range = calculateRange(balance, size);
      printf("The range is: %.2f\n", range);
    } else if (choice == 10) {
      float mean = calculateAverage(balance, size);
      float variance = calculateVariance(balance, size, mean);
      printf("The variance is: %.2f\n", variance);
    } else if (choice == 11) {
      float mean = calculateAverage(balance, size);
      float stddev = calculateStandardDeviation(balance, size, mean);
      printf("The standard deviation is: %.2f\n", stddev);
    } else if (choice == 12) {
      sortArray(balance, size);
      printf("Array has been sorted in ascending order.\n");
      printf("First 100 sorted elements:\n");
      printFirst100(balance);

    } else if (choice == 13) {
      printf("Goodbye\n");
    } else {
      printf("Error, please try again.\n");
    }
  }

  return 0;
}

float findMin(float arr[], int size) {
  float min = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] < min)
      min = arr[i];
  }
  return min;
}

float findMax(float arr[], int size) {
  float max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

float calculateAverage(float arr[], int size) {
  float sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum / size;
}

int findIndexOf(float arr[], int size, float num) {
  for (int i = 0; i < size; i++) {
    if (fabs(arr[i] - num) < EPSILON)
      return i;
  }
  return -1;
}

int countOccurrences(float arr[], int size, float num) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (fabs(arr[i] - num) < EPSILON)
      count++;
  }
  return count;
}

void printFirst100(float arr[]) {
  for (int i = 0; i < 100; i++) {
    printf("%.2f ", arr[i]);
    if ((i + 1) % 10 == 0)
      printf("\n");
  }
}

void sortArray(float arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        float temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

float calculateMedian(float arr[], int size) {
  sortArray(arr, size);
  if (size % 2 == 0)
    return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
  else
    return arr[size / 2];
}

float calculateMode(float arr[], int size) {
  int maxCount = 0;
  float mode = arr[0];
  for (int i = 0; i < size; i++) {
    int count = 0;
    for (int j = 0; j < size; j++) {
      if ((int)(arr[i] * 10.0) == (int)(arr[j] * 10.0))
        count++;
    }
    if (count > maxCount) {
      maxCount = count;
      mode = arr[i];
    }
  }
  return mode;
}

float calculateRange(float arr[], int size) {
  float min = findMin(arr, size);
  float max = findMax(arr, size);
  return max - min;
}

float calculateVariance(float arr[], int size, float mean) {
  float sum = 0.0;
  for (int i = 0; i < size; i++) {
    float diff = arr[i] - mean;
    sum += diff * diff;
  }
  return sum / size;
}

float calculateStandardDeviation(float arr[], int size, float mean) {
  float variance = calculateVariance(arr, size, mean);
  return sqrt(variance);
}

