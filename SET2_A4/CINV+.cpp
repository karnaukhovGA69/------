#include <iostream>
#include <vector>
using namespace std;


pair<vector<int>, long long> Count(const vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left;
    int j = mid + 1;
    long long invCount = 0;


    for (int i = left; i <= mid; i++) {
        int k = mid + 1;
        while (k <= right && arr[i] > 2 * arr[k]) {
            k++;
        }
        invCount += (k - (mid + 1));
    }

    i = left;
    j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= right) {
        temp.push_back(arr[j++]);
    }


    return {temp, invCount};
}

long long Merge(vector<int>& arr, int left, int mid, int right) {
    auto [merged, invCount] = Count(arr, left, mid, right);

    for (int k = 0; k < (int)merged.size(); k++) {
        arr[left + k] = merged[k];
    }

    return invCount;
}

long long CountInversions(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;

    long long invLeft = CountInversions(arr, left, mid);
    long long invRight = CountInversions(arr, mid + 1, right);

    long long invMerge = Merge(arr, left, mid, right);

    return invLeft + invRight + invMerge;
}

int main() {
    vector<int> arr = {5, 3, 2, 4, 1};

    cout << "Input array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    long long inversions = CountInversions(arr, 0, arr.size() - 1);

    cout << "Count of SIGNIFICANT inversions: " << inversions << endl;

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}