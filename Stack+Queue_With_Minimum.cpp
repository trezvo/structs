#include <deque>

using long long int ll;

using namespace std;


struct StackWithMin {

	deque<ll> content;
	deque<ll> minimum;

	void push(const ll& x) {
		content.push_back(x);
		
		if (minimum.size() == 0)
			minimum.push_back(x);
		else
			minimum.push_back(min(x, minimum.back()));
	}

	ll back() const {
		return content.back();
	}

	ll get_min() const {
		return minimum.back();
	}

	void pop() {
		content.pop_back();
		minimum.pop_back();
	}

	size_t size() const {
		return content.size();
	}
};


struct QueueWithMin {

	StackWithMin head;
	StackWithMin tail;

	void push(const ll& x) {
		tail.push(x);
	}

	ll front() const {
		return head.back();
	}

	ll get_min() const {
		if (head.size() == 0) {
			return tail.get_min();
		}
		if (tail.size() == 0) {
			return head.get_min();
		}

		return min(head.get_min(), tail.get_min());
	}

	void pop() {
		if (head.size() > 0) {
			head.pop();
			return;
		}

		while (tail.size() > 0) {
			head.push(tail.back());
			tail.pop();
		}

		head.pop();
	}

	size_t size() const {
		return head.size() + tail.size();
	}
};
