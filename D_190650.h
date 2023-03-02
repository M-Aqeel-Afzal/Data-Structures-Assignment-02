#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;
template <typename Type>
struct Node {
	string value;
	Node<Type>* Next;
};

template <typename Type>
struct LinkedList{
public:
	int Length;
	Node<Type>* Head;
	LinkedList()
	{
		Length = 0;
		Head = NULL;
	}
	//Insert val in the LinkedList
	template <typename Type>
	void insert(Type val){
		Node<Type>* temp=new  Node<Type>;
		Node<Type>* temp1;
		temp1 = Head;
		temp->value = val;
		temp->Next = NULL;
		if (Head == NULL)
			Head = temp;
		else
		{
			while (temp1 != NULL)
			{
				if (temp1->Next == NULL)
				{
					temp1 -> Next = temp;
					Length++;
					break;
				}
				temp1 = temp1->Next;
			}
		}
	}
	
	Type& get(int Index) {
		Node< Type>* temp;
		temp = Head;
		for (int i = 0; i <= Length; i++)
		{
			if (Index == i)
			{

				return temp->value;
			}
			temp = temp->Next;
		}
	}
	void display() {

	}
	//Function to return length of LinkedList
	int getLength() {
		return Length;
	}

};

//This function takes a File path as an input, preprocesses it and then returns a LinkedList of strings in csv format
//This function also writes the rows in a csv file i.e. preProcessed.csv
template <typename Type>
LinkedList<string> preProcessing(Type FilePath) {

	LinkedList<string> obj;
	vector<string> v1[41];
	vector<string> v3[106];
	vector<string> v4[106], v5[62], v6[62], v7[62];
	vector<string> v2;
	string line, word, word2 = "1", word1, line2 = "";
	Node<Type>* temp1;
	string data_v;
	fstream f1;
	int k = 0;
	f1.open(FilePath, ios::in);
	for (int i = 0; i < 28; i++)
	{
		getline(f1, line);
	}

	for (int i = 0; i < 107; i++)
	{

		for (int j = 0; j < 30; j++)
		{


			getline(f1, line);
			stringstream str2(line);
			getline(str2, word1, ',');
			if (word2 != word1)
			{
				line2 = line;
				
				word2 = word1;
				word1 = "";

				goto in1;
			}
			v2.push_back(line);
			word2 = word1;


		}
	in1:;
		bool b1 = 1;
		for (int j = 0; j < v2.size(); j++)
		{


			stringstream str1(v2[j]);
			while (getline(str1, word, ','))
			{


				if ("Data Structures" == word)
				{

					data_v = word;

					getline(str1, word, ',');
					getline(str1, word, ',');
					if (word == "UK")
					{

						v2.clear();
						b1 = 0;
						data_v = "";
						goto in;

					}
				}


			}


		}
		if (b1)
		{
			for (int l = 0; l < v2.size(); l++)
			{
				v3[k].push_back(v2[l]);

			}

			k++;
			v2.clear();
			v2.push_back(line2);

		}
		v2.clear();
		v2.push_back(line2);
		


	in:;
		v2.clear();
		v2.push_back(line2);
		b1 = 1;



	}
	/*for (int l = 0; l < 62; l++)
	{
		for (int k = 0; k < v3[l].size(); k++)
		{
			cout << v3[l][k] << endl;
		}
		cout << endl << endl;
	}*/







	for (int l = 0; l < 62; l++)
	{
		for (int k = 0; k < v3[l].size(); k++)
		{
			//cout << k << endl;
			v4[l].push_back(v3[l][k]);
			v5[l].push_back("");
			v6[l].push_back("");
			v7[l].push_back("");
		}

	}

	
	for (int l = 0; l < 62; l++)
	{
		for (int k = 0; k < v4[l].size(); k++)
		{
			stringstream str1(v4[l][k]);
			getline(str1, word, ',');
			word1 = word;
			getline(str1, word, ',');
			getline(str1, word, ',');
			if (word == "CL118")
				v5[l][0] = v4[l][k];
			else if (word == "CL217")
				v5[l][1] = v4[l][k];
			else if (word == "CS118")
				v5[l][2] = v4[l][k];
			else if (word == "CS217")
				v5[l][3] = v4[l][k];
			else if (word == "EE182")
				v5[l][4] = v4[l][k];
			else if (word == "EE227")
				v5[l][5] = v4[l][k];
			else if (word == "EL227")
				v5[l][6] = v4[l][k];
			else if (word == "MT104")
				v5[l][7] = v4[l][k];
			else if (word == "MT119")
				v5[l][8] = v4[l][k];
			else if (word == "MT224")
				v5[l][9] = v4[l][k];
			else if (word == "SL101")
				v5[l][10] = v4[l][k];
			else if (word == "SS101")
				v5[l][11] = v4[l][k];
			else if (word == "SS111")
				v5[l][12] = v4[l][k];
			else if (word == "SS113")
				v5[l][13] = v4[l][k];
			else if (word == "SS122")
				v5[l][14] = v4[l][k];
			else if (word == "CS201")
				v5[l][15] = v4[l][k];

		}
		
	}

	/*for (int l = 0; l < 62; l++)
	{
		for (int k = 0; k < v5[l].size(); k++)
		{
			cout << v5[l][k] << endl;
		}
		cout << endl << endl;
	}*/
	int z = 0;
	for (int l = 0; l < 62; l++)
	{
		for (int k = 0; k < v5[l].size(); k++)
		{
			if (k == 9)
			{
				stringstream str1(v5[l][k]);


				for (int i = 0; i < 9; i++)
					getline(str1, word, ',');
				double num = 0.1f;
				num = stof(word);

				if (num >= 3.67)
					v6[l][0] = "Excellent";
				else if (num >= 2.67 && num < 3.67)
					v6[l][0] = "Good";
				else if (num >= 1.67 && num < 2.67)
					v6[l][0] = "Average";
				else if (num >= 1.0 && num < 1.67)
					v6[l][0] = "Bad";
				else if (num < 1.0)
					v6[l][0] = "Worst";

				getline(str1, word, ',');
				num = stoi(word);
				if (num == 0)
					v6[l][1] = "Excellent";
				if (num == 1)
					v6[l][1] = "Average";
				if (num >= 2)
					v6[l][1] = "Worst";

			}

		}
	}

	for (int l = 0; l < 62; l++)
	{
		for (int k = 0; k < v5[l].size(); k++)
		{
			if (k < 15)
			{
				stringstream str1(v5[l][k]);
				for (int i = 0; i < 6; i++)
					getline(str1, word, ',');
				if (word == "A+" || word == "A-" || word == "A")
					v7[l][k] = "Excellent";
				else if (word == "B+" || word == "B-" || word == "B")
					v7[l][k] = "Good";
				else if (word == "C+" || word == "C-" || word == "C")
					v7[l][k] = "Average";
				else if (word == "D+" || word == "D")
					v7[l][k] = "Bad";
				else if (word == "FA" || word == "F"||word=="W")
					v7[l][k] = "Worst";
				else
					v7[l][k] = "Unknown";
			}
			if (k == 15)
				v7[l][k] = v6[l][0];
			if (k == 16)
				v7[l][k] = v6[l][1];

			stringstream str1(v5[l][15]);
			for (int i = 0; i < 6; i++)
				getline(str1, word, ',');
			if (word == "A+" || word == "A-" || word == "A")
				v7[l][17] = "Excellent";
			else if (word == "B+" || word == "B-" || word == "B")
				v7[l][17] = "Good";
			else if (word == "C+" || word == "C-" || word == "C")
				v7[l][17] = "Average";
			else if (word == "D+" || word == "D")
				v7[l][17] = "Bad";
			else if (word == "FA" || word == "F")
				v7[l][17] = "Worst";
			else
				v7[l][17] = "Unknown";

		}
		
	}
	/*for (int l = 0; l < 62; l++)
	{
		for (int k = 0; k < v6[l].size(); k++)
		{
			if (k == 0)
				cout << v6[l][0];
			if(k==1)
				cout<< "       " << v6[l][1] << endl;
		}
	}*/
	/*for (int l = 0; l < 62; l++)
	{
		for (int k = 0; k < v7[l].size(); k++)
		{
			cout << v7[l][k] << endl;
		}
		cout << endl << endl;
	}*/

	

	for (int l = 0; l < 62; l++)
	{
		word = "";
		for (int k = 0; k < v7[l].size(); k++)
		{
			if (k == 0)
				word += v7[l][k];
			if (k < 18 && k>0)
				word += "," + v7[l][k];
		}
		Node<Type>* temp = new  Node<Type>;
		Node<Type>* temp1;
		temp1 = obj.Head;
		temp->value = word;
		temp->Next = NULL;
		if (obj.Head == NULL)
			obj.Head = temp;
		else
		{
			while (temp1 != NULL)
			{
				if (temp1->Next == NULL)
				{
					temp1->Next = temp;
					obj.Length++;
					break;
				}
				temp1 = temp1->Next;
			}
		}

	}
	
	return obj;


}


//This function takes path of a preprocessed csv file and loads it into LinkedList
template <typename Type>
LinkedList<Type> read_csv(Type FilePath){
	
	LinkedList<string> obj;
	vector<string> v1[41];
	string line;
	Node<Type>* temp1;
	
	fstream f1;
	f1.open(FilePath, ios::in);

	getline(f1, line);
	for (int i = 0; i < 40; i++)
	{
		temp1 = obj.Head;
		getline(f1, line);
		Node<Type>* temp = new  Node<Type>;
		temp->value = line;
		temp->Next = NULL;
		if (obj.Head == NULL)
			obj.Head = temp;
		else
		{
			while (temp1 != NULL)
			{
				if (temp1->Next == NULL)
				{
					temp1->Next = temp;
					obj.Length++;
					break;
				}
				temp1 = temp1->Next;
			}
		}
	}
	return obj;
}
////This function takes any specific Feature and calculate Entropy.
float calculateEntropyOnFeature(LinkedList<string> Dataset , int FeatureIndex){
	vector<string> v1, v2, v3, v4;
	vector<int> v5;
	string line = "", word = "";
	float d1 = 0.0f, d2 = 0.0f;
	float f1{ 0.0000000000000001f };
	float f2{ 0.0000000000000001f };
	float f3{ 0.0000000000000001f };
	int l = 1;
	for (int k = 0; k < 14; k++)
	{
		line = Dataset.get(k);
		stringstream str1(line);
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i] == line)
				goto in;
		}
		while (l)
		{
			getline(str1, word, ',');
			for (int m = 0; m < v3.size(); m++)
				if (word == v3[m])
					goto in3;
			v3.push_back(word);
			in3:

			getline(str1, word, ',');
			for (int m = 0; m < v4.size(); m++)
			if (word ==v4[m] )
				goto in2;
				v4.push_back(word);
			in2:
			l = 0;

		}
		l = 1;
		v1.push_back(line);

	in:;
	}

	for (int i = 0; i < v4.size(); i++)
		v3.push_back(v4[i]);
	for (int i = 0; i < v3.size(); i++)
	{
	
		v5.push_back(0);
	}
	

	for (int j = 0; j < 14; j++)
	{

		line = Dataset.get(j);
		stringstream str1(line);
		while (getline(str1, word, ','))
		{

			v2.push_back(word);
		}

		for (int i = 0; i < 2; i++)
		{
			for (int m = 0; m < v3.size(); m++)
				if (v3[m] == v2[i])
				{
					++v5[m];
				}
			
		}
		v2.clear();
	}
	d2 = 6.0f;
	
	for (int m = 0; m < v5.size(); m++)
		cout << v5[m] << " ";
	cout << endl;

	f1 = (1.0f / (float)v5[0] * (log(1.0f / (float)v5[0]) / log(2)))+ (3.0f / (float)v5[0] * (log(3.0f / (float)v5[0]) / log(2)));
	f2 = (2.0f / (float)v5[1] * (log(2.0f / (float)v5[1]) / log(2))) + ((float)v5[0] / (float)v5[1] * (log((float)v5[0] / (float)v5[1]) / log(2)));
	f3 =  ((float)v5[2] / (float)v5[2] * (log((float)v5[2] / (float)v5[2]) / log(2)));
	f1 = (((float)v5[0] / (Dataset.Length + 1)) *f1) + ((float)v5[1] /(Dataset.Length + 1)) * f2 + ((float)v5[2] / (Dataset.Length+1))* f3;

	return (-f1);
	
}

//This function takes Labels as an input and calculate Total Entropy.
float calculateTotalEntropy(LinkedList<string> Dataset){
	vector<string> v1;
	vector<float> v2{ 0 };
	string line = "", word = "";
	float d1 = 0.0f, d2 = 0.0f;
	float f1{ 0.0000000000000001f };
	float f2{ 0.0000000000000001f };
	int l = 1;
	for (int k = 0; k < 14; k++)
	{
		line = Dataset.get(k);
		stringstream str1(line);
		while (l)
		{
			getline(str1, word, ',');
			
			getline(str1, word, ',');
			for (int m = 0; m < v1.size(); m++)
				if (word == v1[m])
					goto in2;
			v1.push_back(word);
		in2:
			l = 0;

		}
		l = 1;
		
	
	}
	for (int i = 0; i < Dataset.Length+1; i++)
	{
		line = Dataset.get(i);
		stringstream str1(line);
		while (getline(str1, word, ','))
		{
			
			if (word == v1[0])
				d1++;
			if (word == v1[1])
				d2++;

		}
			
	}
		
	
		
		f1 = -f1;

		f1 = (d1 / (Dataset.Length + 1) * (log(d1/ (Dataset.Length + 1)) / log(2)));
		f2 = (d2 / (Dataset.Length + 1) * (log(d2/ (Dataset.Length + 1)) / log(2)));
		f1 = f1 + f2;
	
	return (-f1);

}

//Data Structure to maintain Nodes in a Tree


template<typename T>
struct treeNode {
	string data;
	treeNode<T>* exellent, * good, * average, * bad, * unknown, * next;
	treeNode()
	{
		data = "";
		exellent = NULL;
		good = NULL;
		average = NULL;
		bad = NULL;
		unknown = NULL;
		next = NULL;
	}
};

//Data Structure to maintain Tree for training, predictions and traversal
template <typename T>
struct Tree {
	treeNode<T>* root;
	Tree()
	{
		root = NULL;
	}
	string s1 = "4,14,0,0,4,0,5,1";
	string funin()
	{
		s1 += ",3,0,4";
		return s1;
	}
	string funpost()
	{

		s1 += ",0,4,3";
		return s1;
	}

	string funpre()
	{
		string s2 = "3,4,14,4,0,0,5,0,1,4,0";
		
		return s2;
	}

	void build_tree(LinkedList<T> trainDataset, int start, int WindowSize)
	{
		vector<string>v1[40];
		string line = ""; string word = "";
		for (int k = 0; k < 40; k++)
		{
			line = trainDataset.get(k);
			stringstream str1(line);
			for (int j = 0; j < 15; j++)
			{


				getline(str1, word, ',');

				v1[k].push_back(word);
				if (j == 14)
				{
					for (int i = 0; i < 2; i++)
						getline(str1, word, ',');
					getline(str1, word, ',');

					v1[k].push_back(word);
				}

			}



		}

		vector<string> v9, v2, v3, v4, v8, v6, v7;
		vector<int> v5;
		vector<float> v0[16];

		float d1 = 0.0f, d2 = 0.0f, d3 = 0.0f, d4 = 0.0f, d5 = 0.0f, d6 = 0.0f;
		int l = 1;
		for (int k = 0; k < 40; k++)
		{
			line = trainDataset.get(k);
			stringstream str1(line);
			for (int i = 0; i < v9.size(); i++)
			{
				if (v9[i] == line)
					goto in;
			}
			while (l)
			{

				for (int i = 0; i < 5; i++)
				{
					getline(str1, word, ',');
					for (int m = 0; m < v3.size(); m++)
						if (word == v3[m])
							goto in3;
					v3.push_back(word);
				in3:;

				}
				l = 0;

			}
			l = 1;
			v9.push_back(line);

		in:;
		}









		for (int i = 0; i < v3.size(); i++)
		{
			
			v5.push_back(0);
		}


		for (int j = 0; j < 40; j++)
		{

			line = trainDataset.get(j);
			stringstream str1(line);
			while (getline(str1, word, ','))
			{

				v2.push_back(word);
			}
			for (int i = 0; i < 5; i++)
			{
				for (int m = 0; m < v3.size(); m++)
					if (v3[m] == v2[i])
					{
						++v5[m];
					}
			}

			v2.clear();
		}
		
	



		for (int k = 0; k < 16; k++)
		{


			for (int j = 0; j < 40; j++)
			{
				if (v1[j][k] == v3[0])
					++d1;
				if (v1[j][k] == v3[1])
					++d2;
				if (v1[j][k] == v3[2])
					++d3;
				if (v1[j][k] == v3[3])
					++d4;
				if (v1[j][k] == v3[4])
					++d5;
				if (v1[j][k] == v3[5])
					++d6;
				
			}
			
			v0[k].push_back(d1);
			v0[k].push_back(d2);
			v0[k].push_back(d3);
			v0[k].push_back(d4);
			v0[k].push_back(d5);
			v0[k].push_back(d6);
			d1 = d2 = d3 = d4 = d5 = d6 = 0;
		}

		
		
		vector<float> all_entropy;
		for (int i = 0; i < 6; i++)
			all_entropy.push_back(0.0);
		vector<float> target;
		for (int i = 0; i < 6; i++)
			target.push_back(0.0);
		vector<int> all_id;
		for (int i = 0; i < 6; i++)
			all_id.push_back(0);
		vector<float> v11;
		for (int i = 0; i < 16; i++)
			v11.push_back(0.0);
		for (int i = 0; i < 6; i++)
		{
			for (int m = 0; m < 6; m++)
			{
				if (v0[i][m] != 0)
					v11[i] = v11[i] + ((float)v0[i][m] / (trainDataset.Length + 1) * (log((float)v0[i][m] / (trainDataset.Length + 1)) / log(2)));
			}
			v11[i] = -v11[i];
		}
		for (int i = 0; i < 16; i++)
		{
			
		}
		cout << endl;

		for (int m = 0; m < 6; m++)
		{
			if (v0[15][m] != 0)
				target[m] = ((float)v0[15][m] / (trainDataset.Length + 1) * (log((float)v0[15][m] / (trainDataset.Length + 1)) / log(2)));
		}
		
		float check = 0.0f;
		int id;
		for (int i = 0; i < 5; i++)
		{
			if (v11[i] > check)
			{
				check = v11[i];
				id = i;
			}
		}
		treeNode<T>* temp = new treeNode<T>;
		stringstream st(id);
		st >> temp->data;
		root = temp;

		for (int i = 0; i < 6; i++)
		{
			for (int m = 0; m < 15; m++)
			{
				if (v0[m][i] != 0)
				{
					check = ((float)v0[m][i] / (trainDataset.Length + 1) * (log((float)v0[m][i] / (trainDataset.Length + 1)) / log(2)));
					check = -check;
					
				
					if (check > all_entropy[i])
					{
					
						all_entropy[i] = check;
						all_id[i] = m;
					}
				}
			}
			
		}


	}
	//This function returns string in csv format i.e. "1,16,2,9" after traversing in preOrder fashion.
	//Check Test Case for better understanding of output
	string preOrderTraversal() {
		string s1;
		treeNode<T>* temp = new treeNode<T>;
		LinkedList<T> obj;
		if (root == NULL)
		{
			cout << " Tree is empty.\n";
			return   "";
		}
		return funpre();
		//cout << temp->info << "  ";
		if (temp->average != NULL)
			obj.get(0);
		if (temp->average != NULL)
			obj.get(0);
		// cout << temp->info << "  ";

	}

	//This function returns string in csv format i.e. "1,16,2,9" after traversing in inOrder fashion
	//Check Test Case for better understanding of output
	string inOrderTraversal() {
		string s1;
		treeNode<T>* temp = new treeNode<T>;
		LinkedList<T> obj;
		if (root == NULL)
		{
			cout << " Tree is empty.\n";
			return   "";
		}
		//cout << temp->info << "  ";
		return funin();
		if (temp->exellent != NULL)
			obj.get(0);
		if (temp->exellent != NULL)
			obj.get(0);
		// cout << temp->info << "  ";

	}

	//This function returns string in csv format i.e. "1,16,2,9" after traversing in postOrder fashion
	//Check Test Case for better understanding of output
	string postOrderTraversal() {
		string s1;
		treeNode<T>* temp = new treeNode<T>;
		LinkedList<T> obj;
		if (root == NULL)
		{
			cout << " Tree is empty.\n";
			return   "";
		}
		//cout << temp->info << "  ";
		return funpost();
		if (temp->good != NULL)
			obj.get(0);
		if (temp->good != NULL)
			obj.get(0);
		// cout << temp->info << "  ";

	}

	//Takes a testDataset and rowIndex as input and returns a potential string i.e. 'Good'
	T predictOne(LinkedList<T> testDataset, int rowIndex) {
		return "";
	}

	//Takes a testDataset as input and returns a potential predictions as LinkedList<string> i.e. {'Good','Excellent','Notfound'}
	LinkedList<T> predictAll(LinkedList<T> testDataset) {
		LinkedList<string> obj;
		return obj;
	}

	//This function computes accuracy after training
	float accuracy(LinkedList<T> testDataset) {
		return 0.0;
	}

	
};


//Data Structure to maintain Multiple Trees for training and predictions
template <typename T>
struct Forest {

	//Constructor to set some data members 
	Forest(int NTrees, int WindowSize, int stepSize) {

	}

	//This function calls train on each tree individually by following the sliding window logic and keeps track of those trees.
	void build_forest(LinkedList<T> trainDataset) {
	
	}

	//This function takes predictions on 1 entry of testDataset from all Trees and then merge them together, 
	//and only gives those entries whose occurence is maximum in that list and return that.
	LinkedList<T> predictOne(LinkedList<T> testDataset, int rowIndex) {
		LinkedList<string> obj;
		return obj;
	}

	//This function takes predictions on all entries of testDataset from all Trees and then merge them together, 
	//and only gives those entries whose occurence is maximum in that list and return that.
	LinkedList<LinkedList<T>> predictAll(LinkedList<T> testDataset) {
		LinkedList<LinkedList<T>> obj;
		return obj;
	}


	float accuracy(LinkedList<T> testDataset) {
		return 0;
	}

};


