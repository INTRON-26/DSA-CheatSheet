class Solution:
  def reverseWords(self, s: str) -> str:
    temp = s.split()
    temp.reverse()
    print(temp)
    res = ""
    for i in range(0,len(temp)):
      if i == len(temp)-1:
        res+=temp[i]
      else:
        res+=temp[i]+" "
    return res
