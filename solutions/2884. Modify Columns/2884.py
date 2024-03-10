# Time complexity: O(n)
# Space complexity: O(n)
import pandas as pd

def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
  employees['salary'] = employees['salary'] * 2
  return employees