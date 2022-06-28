#include <iostream>
#include <vector>
#include <random>

int compares = 0;
int copies = 0;
 
std::vector<int> insertion_sort(std::vector<int>& arr){
   if (arr.size() < 2)
       return arr;
   int i, j, k;
   for(size_t i = 1; i < arr.size(); i++){
       k = arr[i];
       j = i - 1;
  
   while(j >= 0 && arr[j] > k) {
           arr[j + 1] = arr[j];
           j = j - 1;
           compares++;
           copies++;
       }
       arr[j + 1] = k;
   }
   return arr;
}

void printvec(std::vector<int>& vec){
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}
 
int main(){
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 10000);
    std::vector<int> vec;
    for(int i = 0; i < 100; i++){
        vec.push_back(dist(rd));
    }
    printvec(vec);
    std::cout << std::endl;
    insertion_sort(vec);
    printvec(vec);
    std::cout << "Compares: " << compares << ", copies: " << copies << std::endl;
}
