function LCS(x, y) {
  let subsequence = "";
 
 
  for (let i = 0; i < x.length; i++)
    {
      if (y.includes(x[i]) && !subsequence.includes(x[i]))
        {
          subsequence += x[i];
        }
    }
  
  return subsequence;
}

function alreadyFound(xchar, y) {
  
  
  
}


console.log(LCS('ANOTHERTEST', 'NOTTEST'));
