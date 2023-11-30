# Linux File Access Permissions
- rw- r-- r--   # Symbolic Notation
6 4 4   # Octal Notation

# Linux User Types
1. Owner - The owner of the file.
2. Group - The group the file belongs to.
3. Others - Everyone else.

# Access Permissions
1. Read (r) - The file can be read.
2. Write (w) - The file can be written.
3. Execute (x) - The file can be executed as a program.

# Setting Permissions using chmod
chmod [options] mode[,mode] file...

# Examples
chmod 755 example.txt # Set the permissions of example.txt to -rwxr-xr-x
chmod a+x example.txt # Give all users execute permission
chmod u+rw example.txt # Give the owner read and write permissions