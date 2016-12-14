int bin(ll x)
{
    int low=1,high=n;
    while(low<high-1)
    {
        int mid = (low+high)/2;
        if(a[mid]>=x && a[mid-1]<x)return mid;
        else if(a[mid]<x)low=mid+1;
        else high = mid-1;
    }
    if(a[low]>=x)return low;
    else if(a[high]>=x)return high;
    return -1;
}
