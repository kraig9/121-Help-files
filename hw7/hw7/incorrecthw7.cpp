#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

//hw 6 function
int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>> g, vector<vector<int>> b, int color_r, int color_g, int color_b, int start_row) {
	int col = heightMap.at(0).size();
	int row = heightMap.size();
	int curr_row = start_row;
	int up, forward, down;
	int tot_dist;

	r.at(start_row).at(0) = color_r;
	g.at(start_row).at(0) = color_g;
	b.at(start_row).at(0) = color_b;

	for (int i = 0; i < col - 1; i++) {
		
		if (curr_row > 0) {
			up = abs(heightMap[curr_row - 1][i + 1] - heightMap[curr_row][i]);
		}
		else {
			up = INT_MAX;
		}

		if (curr_row < row - 1) {
			down = abs(heightMap[curr_row + 1][i + 1] - heightMap[curr_row][i]);
		}
		else {
			down = INT_MAX;
		}

		forward = abs(heightMap[curr_row][i + 1] - heightMap[curr_row][i]);

		if (up < forward && up < down) {
			tot_dist = tot_dist + up;
			curr_row--;
		}
		else if (forward < up && down < forward) {
			tot_dist = tot_dist + forward;
		}
		else if (down < up && down < forward) {
			tot_dist = tot_dist + down;
			curr_row++;
		}
		else if (up == forward) {
			tot_dist = tot_dist + forward;
		}
		else if (up == down) {
			tot_dist = tot_dist + down;
			curr_row++;
		}
		else if (forward == down) {
			tot_dist = tot_dist + forward;
		}

		r.at(curr_row).at(i + 1) = color_r;
		g.at(curr_row).at(i + 1) = color_g;
		b.at(curr_row).at(i + 1) = color_b;
	}
	return tot_dist;
}

void printMapNumbers(ostream& out, vector<vector<int> >& m) {
	for (int i = 0; i < m.size(); i++) {
		out << "Row " << i << endl;
		for (int j = 0; j < m.at(i).size(); j++) {
			out << m.at(i).at(j) << " ";
		}
		out << endl;
	}
}

void printPPMFile(ofstream& file, int nrows, int ncols,
	vector<vector<int> > r_values, vector<vector<int> > g_values,
	vector<vector<int> > b_values) {
	// TODO check for output error
	file << "P3" << endl;
	file << ncols << " " << nrows << endl << "255" << endl;
	for (int i = 0; i < r_values.size(); i++) {
		for (int j = 0; j< r_values.at(i).size(); j++) {
			file << r_values.at(i).at(j) << " " << g_values.at(i).at(j) << " " << b_values.at(i).at(j) << " ";
		}
		file << endl;
	}
}

int main()
{
	int nrows, ncols;
	cout << "Enter number of rows and columns:\n";
	cin >> nrows;
	if (!cin.good()) {
		cerr << "invalid input. bye!\n";
		return -1;
	}
	cin >> ncols;
	if (!cin.good()) {
		cerr << "invalid input. bye!\n";
		return -1;
	}

	cout << "Enter name of input file:\n";
	string data_file_name;
	cin >> data_file_name;
	if (!cin.good()) {
		cerr << "Failed to read name of input file. Giving up, bye!\n";
		return 1;
	}

	ifstream in_file{ data_file_name };
	if (!in_file.is_open()) {
		cerr << "Failed to open input file " << data_file_name << ". Giving up, bye!\n";
		return 1;
	}

	vector<vector<int> > map(nrows, vector<int>(ncols));
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			in_file >> map.at(i).at(j);
			if (!in_file.good()) { // error in the input
				cerr << "Error during input from file (i is " << i << ", j is " << j << "). Giving up, bye!\n";
				//printMapNumbers(cout, map);
				return -2;
			}
		}
	}

	// determine min and max
	int max = 0; // We know 0 is lowest possible value
	int min = map.at(0).at(0);
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			if (map.at(i).at(j) > max) {
				max = map.at(i).at(j); // set new max
			}
			if (map.at(i).at(j) < min) {
				min = map.at(i).at(j); // set new min
			}
		}
	}
	cout << "min is " << min << "; max is " << max << endl;

	vector<vector<int> > r_values(nrows, vector<int>(ncols));
	vector<vector<int> > g_values(nrows, vector<int>(ncols));
	vector<vector<int> > b_values(nrows, vector<int>(ncols));

	// compute gray scale values and put in color vectors
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			int elev = map.at(i).at(j);
			// ensure we get accurate results by using floating point division rather
			//  than integer division, so cast numerator and denominator to double
			double delev = static_cast<double>(elev - min) / static_cast<double>(max - min) * 255;
			//cout << "delev " << delev << " ";
			int scaled_value = static_cast<int>(delev); // cast double to an int color value
														// assign color value to each color vector
			r_values.at(i).at(j) = g_values.at(i).at(j) = b_values.at(i).at(j) = scaled_value;
		}
	}

	int delta_d = colorPath(map, r_values, g_values, b_values, 252, 25, 63, 0);
	int max_row = 0;
	for (int i = 1; i < nrows; i++) {
		int distance = colorPath(map, r_values, g_values, b_values, 252, 25, 63, i);
		if (distance < delta_d) {
			delta_d = distance;
			max_row = i;
		}
	}
	colorPath(map, r_values, g_values, b_values, 31, 253, 13, max_row);

	ofstream rgb_file{ data_file_name + ".ppm" };

	printPPMFile(rgb_file, nrows, ncols, r_values, g_values, b_values);

	//printMapNumbers(cout, map);

	//file closes automatically

}