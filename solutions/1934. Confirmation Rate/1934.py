import pandas as pd

def confirmation_rate(signups: pd.DataFrame, 
                      confirmations: pd.DataFrame) -> pd.DataFrame:
  merged_df = pd.merge(signups, confirmations, on='user_id', how='left')
  merged_df['confirmation_flag'] = (
    merged_df['action'] == 'confirmed'
  ).astype(int)
  df = merged_df.groupby('user_id')['confirmation_flag'].mean().reset_index()
  df['confirmation_rate'] = df['confirmation_flag'].round(2).fillna(0)

  return df[['uder_id', 'confirmation_rate']]