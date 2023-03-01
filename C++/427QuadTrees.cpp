/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/construct-quad-tree/
 */
#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
class Solution
{
public:
    bool isSame(vector<vector<int>> &grid, int x, int y, int length)
    {
        int v = grid[x][y];
        for (int i = x; i < x + length; i++)
        {
            for (int j = y; j < y + length; j++)
            {
                if (grid[i][j] != v)
                    return false;
            }
        }
        return true;
    }
    Node *solve(vector<vector<int>> &grid, int x, int y, int length)
    {
        if (isSame(grid, x, y, length))
        {
            return new Node(grid[x][y], true);
        }
        else
        {
            Node *root = new Node(1, false);
            int n = length / 2;
            root->topLeft = solve(grid, x, y, n);
            root->topRight = solve(grid, x, y + n, n);
            root->bottomLeft = solve(grid, x + n, y, n);
            root->bottomRight = solve(grid, x + n, y + n, n);
            return root;
        }
    }
    Node *construct(vector<vector<int>> &grid)
    {
        return solve(grid, 0, 0, grid.size());
    }
};