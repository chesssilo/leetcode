import pandas as pd

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
  conditions = {
    'Low Salary': accounts['income'] < 20000,
    'Average Salary': (accounts['income'] >= 20000) & 
                      (accounts['income'] <= 50000),
    'High Salary': accounts['income'] > 50000
  }
    
  data = {
    'category': [],
    'accounts_count': []
  }
    
  for category, condition in conditions.items():
    data['category'].append(category)
    data['accounts_count'].append(accounts[condition].shape[0])
    
  return pd.DataFrame(data)