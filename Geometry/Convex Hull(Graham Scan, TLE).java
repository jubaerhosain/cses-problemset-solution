import java.util.*;

public class Solution {

    private long orientation(long[] a, long[] b, long[] c) {
        //val = 0 collinear, val > 0 clockwise, val < 0 anti-clockwise
        return (b[1] - a[1])*(c[0] - b[0]) - (c[1] - b[1])*(b[0] - a[0]);
    }

    private long distance(long[] a, long[] b) {
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
    
    private long[] findBottomLeft(long[][] points, int n) {
        long[] bottomLeft = points[0];
        
        for(int i = 1; i < n; i++) {
            if(points[i][1] < bottomLeft[1])
                bottomLeft = points[i];
            else if(points[i][1] == bottomLeft[1])
                bottomLeft = (points[i][0] < bottomLeft[0]) ? points[i] : bottomLeft;
        }
        
        return bottomLeft;
    }
    
    public long[][] convexHull(long[][] points) {
        if(points.length <= 3)
            return points;
        
        int n = points.length;
        long[] start = findBottomLeft(points, n);
        Arrays.sort(points, new Comparator<long[]>() {
            public int compare(long[] a, long[] b) {
                if(orientation(start, a, b) < 0) 
                    return -1;
                else if(orientation(start, a, b) > 0)
                    return 1;
                
                long dist = distance(start, a) - distance(start, b);
                return (dist < 0) ? -1 : 1;
            } 
        });
        
        //if collinear point in the end then reverse those
        //points for min distance point stays at far distance from start
        int i = n-1;
        while(i >= 0 && orientation(start, points[i], points[n-1]) == 0)
            i--;
        
        int left = i+1, right = n-1;
        while(left < right) {
            long[] tmp = points[left];
            points[left] = points[right];
            points[right] = tmp;
            left++; right--;
        }
        
        Stack<long[]> stack = new Stack<>();
        stack.push(points[0]);
        stack.push(points[1]);
        for (int j = 2; j < points.length; j++) {
            long[] top = stack.pop();
            while (orientation(stack.peek(), top, points[j]) > 0)
                top = stack.pop();
            stack.push(top);
            stack.push(points[j]);
        }
        
        return stack.toArray(new long[stack.size()][]);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        long[][] points = new long[n][2];
        for(int i = 0; i < n; i++) {
            points[i][0] = scan.nextLong(); 
            points[i][1] = scan.nextLong(); 
        }

        Solution obj = new Solution();
        long[][] hull = obj.convexHull(points);

        System.out.println(hull.length);
        for(int i = 0; i < hull.length; i++) {
            System.out.println(hull[i][0] + " " + hull[i][1]);
        }
        
        scan.close();
    }
}
