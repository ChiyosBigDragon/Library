---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# import os\n# import glob\n# import json\n# import sys\n\n# EXTENSIONS =\
    \ {'.cpp', '.hpp'}\n# OUTPUT_FILE = 'cpp.json'\n\n\n# def create_snippet(file_path)\
    \ :\n# \tname = os.path.splitext(os.path.basename(file_path))[0]\n# \twith open(file_path,\
    \ mode='r') as f :\n# \t\ttext = f.read()\n# \tsnippet = {\n# \t\t'prefix': name,\n\
    # \t\t'body': text,\n# \t\t# 'description': name,\n# \t}\n# \treturn snippet\n\
    \n\n# def create_snippets(dir_name):\n# \tsnippets = {}\n# \tfor file_path in\
    \ glob.iglob(os.path.join(dir_name, '**', '*'), recursive=True):\n# \t\text =\
    \ os.path.splitext(file_path)[1]\n# \t\tif os.path.isfile(file_path) and ext in\
    \ EXTENSIONS:\n# \t\t\tfile_name = os.path.basename(file_path)\n# \t\t\tsnippets[file_name]\
    \ = create_snippet(file_path)\n# \treturn snippets\n\n\n# if __name__ == '__main__':\n\
    # \tsnippets = create_snippets(sys.argv[1])\n# \twith open(OUTPUT_FILE, mode='w')\
    \ as f:\n# \t\tf.write(json.dumps(snippets, ensure_ascii=False, indent=4))"
  dependsOn: []
  isVerificationFile: false
  path: snippet.py
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet.py
layout: document
redirect_from:
- /library/snippet.py
- /library/snippet.py.html
title: snippet.py
---
