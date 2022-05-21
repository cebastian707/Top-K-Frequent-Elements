/*By::Cebastian Santiago 
* Leetcode 347
*/
#include<iostream>
#include<vector>
#include<queue>
#include<map>



std::vector<int> topKFrequenthelper(std::map<int, int> top,int k) {
	//variables
	std::priority_queue<std::pair<int, int>> kfrequent;
	std::vector<int> topk;

	//loop through the map
	for (auto& i : top) {
		kfrequent.push(std::make_pair(i.second, i.first));
	}

	//pop the heap k times and store them in a vector
	while (k > 0){
		topk.push_back(kfrequent.top().second);
		kfrequent.pop();
		k--;
	}

	return topk;
}




std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
	//variables
	std::map<int, int>track;

	//if k is equal to one and only one element in the vector
	if (k == 1 && nums.size() == 0){
		return nums;
	}
	

	//loop through vector
	for (size_t i = 0; i < nums.size(); i++) {
		//check if we havent seen this number before
		if (track.find(nums[i]) == track.end()){
			//add to map if we havent seen it and set count to one
			track.insert({ nums[i],1 });
		}
		//we already seen it just increment the times 
		//we seen this number
		else{
			track[nums[i]]++;
		}
	}

	return topKFrequenthelper(track, k);
}



int main() {
	std::vector<int> nums = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
	std::vector<int> ans;

	ans = topKFrequent(nums, 10);

	for (size_t i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << std::endl;
	}
	return 0;
}