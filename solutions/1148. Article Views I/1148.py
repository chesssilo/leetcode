import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
  df = views[views['author_id'] == views['viewer_id']]['author_id'] \
      .drop_duplicates() \
      .sort_values() \
      .reset_index(drop=True) \
      .to_frame()
  df.columns = ['id']

  return df