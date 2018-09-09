template<class T>
class BITree {

	int size;
	vector<T> tree;

public:

	BITree(int size) : size(size){
		tree.resize(size);
	}

	void update(int idx, T val){
		while(idx <= size){
			tree[idx] += val;
			idx += idx&-idx;
		}
	}

	T get(int idx){
		T res = 0;

		while(idx > 0){
			res += tree[idx];
			idx -= idx&-idx;
		}

		return res;
	}
};