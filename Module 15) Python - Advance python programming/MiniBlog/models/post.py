import os 

class Post: 
    def __init__(self, user, title, content): 
        self.user = user 
        self.title = title 
        self.content = content 

    def get_filename(self): 
        folder = "data/saved_posts" 
        if not os.path.exists(folder): 
            os.makedirs(folder) 
        return os.path.join(folder, f"{self.user.name}_{self.title}.txt") 

    def save_to_file(self): 
        with open(self.get_filename(), "w", encoding="utf-8") as file: 
            file.write(f"Author: {self.user.name}\n") 
            file.write(f"Title: {self.title}\n\n") 
            file.write(self.content) 