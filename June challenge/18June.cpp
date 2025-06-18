// 54. Spiral Matrix
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix)
{
    let r = matrix.length;
    let c = matrix[0].length;
    let arr = [];
    let top = 0, bottom = r - 1, left = 0, right = c - 1;

    while (top <= bottom && left <= right)
    {
        for (let i = left; i <= right; i++)
        {
            arr.push(matrix[top][i]);
        }
        top++;
        for (let i = top; i <= bottom; i++)
        {
            arr.push(matrix[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (let i = right; i >= left; i--)
            {
                arr.push(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (let i = bottom; i >= top; i--)
            {
                arr.push(matrix[i][left]);
            }
            left++;
        }
    }

    return arr;
};
