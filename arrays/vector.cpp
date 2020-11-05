
#include <vector>
#include <iostream>
 
using namespace std;
 
struct Point
{
	double x;
	double y;
	Point()
	{
		x = 0;
		y = 0;
	}
};
 
 
int main()
{
	vector<Point> m_testPoint;
	m_testPoint.clear();
	m_testPoint.shrink_to_fit();
 
	for (int i = 0; i<10; ++i)
	{
		Point temp;
		temp.x = i*i;
		temp.y = i*i;
		m_testPoint.push_back(temp);
	}
 
	cout << "1.subscript" << endl;
	for (int i = 0; i<m_testPoint.size(); ++i)
	{
 
		cout << m_testPoint[i].x << "	" << m_testPoint[i].y << endl;
	}
 
	cout << "2.iter" << endl;
	for (vector<Point>::iterator iter = m_testPoint.begin(); iter != m_testPoint.end(); iter++)
	{
		cout << (*iter).x << "	" << (*iter).y << endl;
	}
 
 	cout << "3.C++11 auto" << endl;
	for (auto iter = m_testPoint.begin(); iter != m_testPoint.end(); iter++)
	{
		cout << (*iter).x << "	" << (*iter).y << endl;
	}
 
	cout << "4.C++11 auto" << endl;
	for (auto i : m_testPoint)
	{
		cout << i.x << "	" << i.y << endl;
	}
    
    vector<int> v;      
    int values[] = {1,3,5,7};
    
    v.insert(v.end(), values+1, values+3);       //3,5
    v.push_back(9);                              //3,5,9
    // v.erase(&v[1]);                              //3,9
    v.insert(v.begin()+1, 4);                    //3,4,9
    v.insert(v.end()-1, 4, 6);                   //3,4,6,6,6,6,9
    v.erase(v.begin()+1, v.begin()+3);           //3,6,6,6,9
    v.pop_back();                                //3,6,6,6
    v.clear();                                   //nothing left

	return 0;
}