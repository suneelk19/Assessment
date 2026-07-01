import tkinter as tk 
from tkinter import messagebox 
import os 
 
from models.user import User 
from models.post import Post 
 
# ---------------- GUI Functions ---------------- 
 
def save_post(): 
    name = entry_name.get().strip() 
    title = entry_title.get().strip() 
    content = text_content.get("1.0", tk.END).strip() 
 
    if not name or not title or not content: 
        messagebox.showwarning("Warning", "All fields are required!") 
        return 
 
    user = User(name) 
    post = Post(user, title, content) 
 
    try: 
        post.save_to_file() 
        messagebox.showinfo("Success", "Post saved successfully!") 
        load_posts() 
        entry_title.delete(0, tk.END) 
        text_content.delete("1.0", tk.END) 
    except Exception as e: 
        messagebox.showerror("Error", str(e)) 
def load_posts(): 
    listbox_posts.delete(0, tk.END) 
    folder = "data/saved_posts" 
    if os.path.exists(folder): 
        for file in os.listdir(folder): 
            if file.endswith(".txt"): 
                listbox_posts.insert(tk.END, file) 
 
def view_post(): 
    try: 
        selected = listbox_posts.get(listbox_posts.curselection()) 
        filepath = os.path.join("data/saved_posts", selected) 
 
        with open(filepath, "r", encoding="utf-8") as file: 
            text_view.delete("1.0", tk.END) 
            text_view.insert(tk.END, file.read()) 
 
    except IndexError: 
        messagebox.showwarning("Warning", "Select a post first!") 
    except FileNotFoundError: 
        messagebox.showerror("Error", "File not found!") 
# ---------------- GUI Design ---------------- 
root = tk.Tk() 
root.title("MiniBlog") 
root.geometry("600x550") 

tk.Label(root, text="MiniBlog", font=("Arial", 18, "bold")).pack(pady=10) 
tk.Label(root, text="User Name").pack() 
entry_name = tk.Entry(root, width=40) 
entry_name.pack() 
tk.Label(root, text="Post Title").pack() 
entry_title = tk.Entry(root, width=40) 
entry_title.pack() 
tk.Label(root, text="Post Content").pack() 
text_content = tk.Text(root, height=6, width=45) 
text_content.pack() 
tk.Button(root, text="Save Post", command=save_post).pack(pady=10) 
tk.Label(root, text="Saved Posts").pack() 
listbox_posts = tk.Listbox(root, width=45) 
listbox_posts.pack() 
tk.Button(root, text="View Post", command=view_post).pack(pady=10) 
tk.Label(root, text="Post View").pack() 
text_view = tk.Text(root, height=8, width=45) 
text_view.pack() 
load_posts() 
root.mainloop()