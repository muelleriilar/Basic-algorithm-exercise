// #include <ranges>
// #include <iostream>
// #include <vector>

// int main() {
//     using namespace std::views;
//     std::vector<int> v{1,2,3,4,5,6,7,8};
//     auto res = all(v) | filter([](int a) { return a%2;}) | take(3);
//     for(const auto& i : res) {
//         std::cout << i << std::endl;
//     }
// }