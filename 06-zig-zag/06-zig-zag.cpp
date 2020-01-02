class Solution {
public:
  string convert(string s, int numRows) {
    int string_length;
    int numColumns;
    string_length = s.length();
    if (numRows > 1) {
      numColumns = string_length * (numRows - 1) / (numRows * 2 - 2) + 1;
    } else {
      numColumns = string_length;
    }
    char array_tmp[numRows][numColumns + 1];
    int col_tmp = 0;
    int row_tmp = 0;
    for (int m = 0; m < numRows; ++m) {
      for (int n = 0; n < numColumns; ++n) {
        array_tmp[m][n] = '\0';
      }
    }
    for (int i = 0; i < string_length; ++i) {
      // printf("%d", string_length);
      array_tmp[row_tmp][col_tmp] = s[i];
      // printf("%c", array_tmp[row_tmp][col_tmp]);
      do {
        row_tmp++;
        if (row_tmp >= numRows) {
          col_tmp++;
          row_tmp = 0;
        }
      } while (!pos_right(row_tmp, col_tmp, numRows));
    }
    string convert_result;
    for (int m = 0; m < numRows; ++m) {
      for (int n = 0; n < numColumns; ++n) {
        if (array_tmp[m][n] != '\0') {
          // printf("%c", array_tmp[m][n]);
          // printf("%d,%d,", m, n);
          convert_result.push_back(array_tmp[m][n]);
        } else {
        }
      }
    }
    return convert_result;
  }

  int pos_right(int row, int column, int numRows) {
    if (numRows == 1)
      return 1;
    else {
      if (column % (numRows - 1) == 0) {
        return 1;
      } else {
        if (row + (column % (numRows - 1)) == numRows - 1) {
          return 1;
        } else {
          return 0;
        }
      }
    }
  }
};
