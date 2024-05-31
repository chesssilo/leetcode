import pandas as pd

def sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
  df = sales.merge(product, on='product_id', how='inner')
  return df[['product_name', 'year', 'price']]