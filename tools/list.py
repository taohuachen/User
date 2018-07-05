# -*- coding: utf-8 -*-

import os

global_dirs = []

for root, dirs, files in os.walk('./'):
    for file in files:
        if file[-2:] == '.h':
            global_dirs.append(root)
            break

with open('./list.txt', 'w') as f:
    for dir in global_dirs:
        dir = dir.replace('./', '$PROJ_DIR$/../')
        dir = dir.replace('\\', '/')
        f.write(dir)
        f.write('\n')
