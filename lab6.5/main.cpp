#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
#define MAX_LEN 100

using namespace std;

int* common_elements(int list1[], int list2[]) {
    int size1 = sizeof(list1)/sizeof(list1[0]); // Calculate size of list1
    int size2 = sizeof(list2)/sizeof(list2[0]); // Calculate size of list2

    int* temp = new int[size1]; // Allocate memory for the temp array

    // Loop over each element in list1
    int index = 0;
    for (int i = 0; i < size1; i++) {
        // Check if the current element in list1 is also in list2
        bool isFound = false;
        for (int j = 0; j < size2; j++) {
            if (list1[i] == list2[j]) {
                isFound = true;
                break;
            }
        }

        // If the element was isFound in both lists, add it to the temp array
        if (isFound) {
            temp[index] = list1[i];
            index++;
        }
    }

    // Create a new array with the exact size of the temp array and copy the elements
    // from the temp array to the new array
    int* finalTemp = new int[index];
    for (int i = 0; i < index; i++) {
        finalTemp[i] = temp[i];
    }

    // Free the memory used by the temp array
    delete[] temp;

    // Return the final temp array and its size
    return finalTemp;
}



int isPalindrome(string s) {
    int length = s.length();
    for (int i = 0; i < length / 2; i++) {
        if (s[i] != s[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}
bool is_prime(int num) {
    if(num < 2) {
        return false;
    }
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}
bool is_anagram(char *word1, char *word2) {
    int number1[26] = {0}, number2[26] = {0};
    int length1 = strlen(word1), length2 = strlen(word2);

    if (length1 != length2) {
        return false;
    }

    for (int i = 0; i < length1; i++) {
        number1[word1[i] - 'a']++;
        number2[word2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (number1[i] != number2[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int list1[]={1,2,3,4,5};
    int list2 []={4,5,6,7,8};
    int *common = common_elements(list1,list2);
    int commonSize = sizeof(common) / sizeof(common[0]);
    for (int i = 0; i < commonSize; i++) {
        cout << common[i] << " ";
    }
    cout<<endl;

    string strings[] = {"level", "radar", "python", "racecar", "madam"};
    int numStrings = sizeof(strings) / sizeof(strings[0]);
    string palindromes[numStrings];
    int numPalindromes = 0;
    for (int i = 0; i < numStrings; i++) {
        if (isPalindrome(strings[i])) {
            palindromes[numPalindromes] = strings[i];
            numPalindromes++;
        }
    }
    cout << "Palindromes: ";
    for (int i = 0; i < numPalindromes; i++) {
        cout << palindromes[i] << " ";
    }
    cout << endl;

    int nums[] = {2, 3, 4,5, 6,7, 9, 10,11, 12,13, 15, 17, 19, 20, 22};
    int size = sizeof(nums)/sizeof(nums[0]);
    int num_primes = 0;

    for(int i = 0; i < size; i++) {
        if(is_prime(nums[i])) {
            num_primes++;
        }
    }

    int primes[num_primes];
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(is_prime(nums[i])) {
            primes[j++] = nums[i];
        }
    }

    cout << "Original List: ";
    for(int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }

    cout << endl << "Prime List: ";
    for(int i = 0; i < num_primes; i++) {
        cout << primes[i] << " ";
    }
    cout<<endl;
    char word[MAX_LEN];
    char word_list[][MAX_LEN] = {"enlist", "google", "inlets", "banana"};
    int n = sizeof(word_list) / sizeof(word_list[0]);

    cout << "Enter a word: ";
    cin >> word;

    for (int i = 0; i < n; i++) {
        if (is_anagram(word, word_list[i])) {
            cout << word_list[i] << endl;
        }

    }

        return 0;
}
