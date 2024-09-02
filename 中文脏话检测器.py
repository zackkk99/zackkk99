import tkinter as tk
from flashtext import KeywordProcessor

# 初始化FlashText关键字处理器
keyword_processor = KeywordProcessor()

# 自定义中文敏感词库
chinese_bad_words = ['操你妈', '傻逼', '死全家']

# 添加脏话词汇到关键字处理器
for word in chinese_bad_words:
    keyword_processor.add_keyword(word, '*' * len(word))

# 处理文本的函数
def censor_text():
    input_text = input_text_box.get("1.0", tk.END).strip()
    censored_text = keyword_processor.replace_keywords(input_text)
    output_text_box.delete("1.0", tk.END)
    output_text_box.insert(tk.END, censored_text)

# 设置替换字符的函数
def set_replacement_char():
    replacement_char = replacement_char_entry.get()
    keyword_processor.clear_keywords()
    for word in chinese_bad_words:
        keyword_processor.add_keyword(word, replacement_char * len(word))
    censor_text()

# 创建主窗口
root = tk.Tk()
root.title("中文脏话检测器")

# 输入文本标签和文本框
input_label = tk.Label(root, text="输入文本:")
input_label.pack()
input_text_box = tk.Text(root, height=10, width=50)
input_text_box.pack()

# 输出文本标签和文本框
output_label = tk.Label(root, text="处理后的文本:")
output_label.pack()
output_text_box = tk.Text(root, height=10, width=50)
output_text_box.pack()

# 替换字符输入框
replacement_char_label = tk.Label(root, text="替换字符:")
replacement_char_label.pack()
replacement_char_entry = tk.Entry(root)
replacement_char_entry.insert(0, "*")  # 设置默认替换字符为 '*'
replacement_char_entry.pack()

# 按钮 - 执行过滤
censor_button = tk.Button(root, text="检测并替换脏话", command=censor_text)
censor_button.pack()

# 按钮 - 设置替换字符
replacement_char_button = tk.Button(root, text="设置替换字符", command=set_replacement_char)
replacement_char_button.pack()

# 启动主循环
root.mainloop()
