#include <iostream>
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
using namespace std;
void show_box(box b);
void set_box(box *b);
int main()
{
	box b = { "Boom boom pow",1.2,2.1,3.1,12.5 };
	show_box(b);
	set_box(&b);
	show_box(b);
	while (1);
	return 0;
}
void show_box(box b)
{
	cout << b.maker << endl;
	cout << b.height << endl;
	cout << b.width << endl;
	cout << b.length << endl;
	cout << b.volume << endl;
}
void set_box(box*b)
{
	b->volume = b->height*b->length*b->width;

}