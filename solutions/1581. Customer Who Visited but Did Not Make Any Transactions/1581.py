import pandas as pd

def find_customers(visits: pd.DataFrame, 
                   transactions: pd.DataFrame) -> pd.DataFrame:
  df = visits.merge(transactions, on='visit_id', how='left')
  df = df[pd.isnull(df['transaction_id'])]

  return df.groupby('customer_id')['visit_id'] \
           .count() \
           .reset_index(name='count_no_trans')