#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
	std::string title;
	int rating;
	double price;
};

bool operator<(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2);
bool ratingup_com(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2);
bool ratingdown_com(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2);
bool priceup_com(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2);
bool pricedown_com(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2);
bool FillReview(Review& rr);
void ShowReview(const std::shared_ptr<Review>& p);

int main()
{
	using namespace std;

	vector<shared_ptr<Review> > books;
	Review temp;
	while (FillReview(temp))
	{
		shared_ptr<Review> pd(new Review(temp));
		books.push_back(pd);
	}
	if (books.size() > 0)
	{
		cout << "Please choose the way to sort: "
			<< "n: normal, a: alpha, r: rating(up), s: rating(down), p: price(up), d: price(down), q: quit\n";
		char a;
		while (cin >> a && a != 'q')
		{
			switch (a)
			{
			case 'r': sort(books.begin(), books.end(), ratingup_com); break;
			case 's': sort(books.begin(), books.end(), ratingdown_com); break;
			case 'p': sort(books.begin(), books.end(), priceup_com); break;
			case 'd': sort(books.begin(), books.end(), pricedown_com); break;
			default:  sort(books.begin(), books.end()); break;
			}
			for_each(books.begin(), books.end(), ShowReview);
			cout << "Please choose the way to sort: "
				<< "n: normal, a: alpha, r: rating(up), "
				<< "s: rating(down), p: price(up), d: price(down), q: quit" << endl;
		}
	}
	return 0;
}

bool FillReview(Review& rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "Enter book rating : ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;
	std::cout << "Enter book price : ";
	std::cin >> rr.price;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const std::shared_ptr<Review>& p)
{
	std::cout << p->rating << "\t" << p->title << "\t" << p->price << std::endl;
}

bool operator<(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2)
{
	if (p1->title < p2->title)
		return true;
	else if (p1->title == p2->title && p1->rating < p2->rating)
		return true;
	else
		return false;
}

bool ratingup_com(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2)
{
	if (p1->rating < p2->rating)
		return true;
	else
		return false;
}

bool ratingdown_com(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2)
{
	if (p1->rating > p2->rating)
		return true;
	else
		return false;
}

bool priceup_com(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2)
{
	if (p1->price < p2->price)
		return true;
	else
		return false;
}

bool pricedown_com(const std::shared_ptr<Review>& p1, const std::shared_ptr<Review>& p2)
{
	if (p1->price > p2->price)
		return true;
	else
		return false;
}