#include<cassert>
#include<iostream>
#include<stdio.h>
//#include<cassert>
//#include<vector>
//#include<string>
//#include<iostream>
//#include<algorithm>
//#include<bits/stdc++.h>
//#include<unordered_set>
//#include<unordered_map>
//#include<set>
//#include<map>
 
using namespace std;
#define LINE 100000
//#define LINE 20
 
int main(void){
	char buffer[LINE];
	int i=0;
	int ch;

	// reading input
	while (i + 1 < LINE){
		ch = getchar();
		if (ch == EOF){
			break;
		}
		else{
			buffer[i] = ch;
			i++;
		}
	}
	buffer[i] = '\0';
	//cout << buffer;

	// parsing input
	int buffer_end = i;
	i = 0; // pointer current char of new string
	int j = 0; // pointer current char of old string
	//int count = 0;

	while (j != buffer_end){
		ch = buffer[j];
		if (/*ch == ' ' ||*/ ch == '\n'){
			while ((/*ch == ' ' && */ch == '\n') && j != buffer_end){
				ch = buffer[++j];
			}
			//if (i !=0 && buffer[i-1] != '|' && j != buffer_end) buffer[i++] = '|';
			if (i !=0 && buffer[i-1] != '|' && j != buffer_end) buffer[i++] = '|';//, count++;
		}
		else if (ch == '/'){
			j++;
			if (j == buffer_end){
				break;
			}
			else if (buffer[j] == '/'){
				j++;
				while (j != buffer_end && buffer[j++] != '\n');
			}
			else if (buffer[j] == '*'){
				j++;
				while (j != buffer_end){
					if (buffer[j] == '*'){
						j++;
						if (j == buffer_end){
							break;
						}
						else if (buffer[j] == '/'){
							j++;
							break;
						}
						else{
							continue;
						}
					}
					j++;
				}
			}
			else{
				buffer[i++] = ch;
			}
		}
		else if (ch == '#' || ch == '|' || ch == '=' || ch == '&'){
			cout << "Warning! Cannot use: " << (char) ch << endl;
			exit(0);
		}
		else{
			buffer[i++] = ch;
			j++;
		}
	}

	buffer[i - (buffer[i-1] == '|')] = '\0';
	cout << buffer;
}
