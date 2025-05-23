<h1 align='center'>Change log started from 7/4/25</h1>
<p>[1] [INIT] - init .gitignore</p>
<p>[2] [INIT] - init src/ directory</p>
<p>[3] [INIT] - init include/ directory</p>
<p>[4] [INIT] - init utils/ directory</p>
<p>[5] [INIT] - init README.md</p>
<p>[6] [INIT] - init scripts/ directory</p>
<p>[7] [NEW_FEATURE] - separating the command name and its switches</p>
<p>[8] [NEW_FEATURE] - pass both prog and switches to the executer function</p>
<p>[9] [NEW_FEATURE] - wrote a helper function to turn a string to lowercase</p>
<p>[10] [BUG_FIXED] - fixed the bug of that related to the left side white space of the cmd</p>
<p>[11] [REMOVED_WARN] - removed the warning related to the const qualifier</p>
<p>[12] [INIT] - executor init</p>
<p>[13] [NEW_UTIL] - wrote str_comp() helper function</p>
<p>[14] [BUG_FIXED] - fixed the bug of the compile.sh script related to the compiling builtin commands</p>
<p>[15] [NEW_CMD] - exit() builtin command init</p>
<p>[16] [MODIFICATION] - removed the strip.h inclusion in the main.c</p>
<p>[17] [NEW_CMD] - echo() builtin command init</p>
<p>[18] [NEW_UTIL] - wrote join() helper function</p>
<p>[19] [REMOVED] - deleted and removed exit builtin command</p>
<p>[20] [MODIFICATION] - changed the executor logic to avoid mamory leak</p>
<p>[21] [MODIFICATION] - changed the return type of the executor</p>
<p>[22] [NEW_CMD] - clear() builtin command init</p>
<p>[23] [CMD_SUP] - added the 'dir' argument and added clear, ls, cd and pwd commands</p>
<p>[24] [NEW_FEATURE] - added the 'dir' variable to the 'uinfo' struct</p>
<p>[25] [BUG_FIXED] - fixed the bug in join util: one additional space at the end of the string</p>
<p>[26] [NEW_CMD] - cd builtin command init</p>
<p>[27] [NEW_CMD] - ls builtin command init</p>
<p>[28] [NEW_CMD] - pwd builtin command init</p>
<p>[29] [NEW_UTIL] - wrote str_cpy() helper function</p>
<p>[30] [BUG_FIXED] - fixed the buffer over flow problem of the cd builtin command</p>
<p>[31] [UPDATE] - update .gitignore</p>
<p>[32] [MODIFICATION] - removed the debbug line from the builtins/cd.c</p>
<p>[33] [NEW_FEATURE] - added 'raw_cmd' parameter and 'BUFFER' macro to the executor function</p>
<p>[34] [NEW_FEATURE] - added the feature to execute non-builtin commands</p>
<p>[35] [NEW_FEATURE] - passing the 'ustng.cmd' strcuture variable to the executor function</p>
<p>[36] [BUG_FIXED] - passed a compatible value to the malloc() function to allocate memory for join() function</p>
<p>[37] [NEW_UTIL] - wrote arr_len() helper function</p>
<p>[38] [BUG_FIXED] - removed an additional \n in output of non-builtin commands</p>
<p>[39] [NEW_CMD] - wrote uptime builtin command</p>
<p>[40] [NEW_CMD] - added uptime to the builtin command handler</p>
<p>[41] [NEW_CMD] - added mkdir and touch to the builtin command handler</p>
<p>[42] [NEW_CMD] - mkdir builtin command init</p>
<p>[43] [NEW_CMD] - touch builtin command init</p>
<p>[44] [BUG_FIXED] - fixed the bug related to the header gaurd's macro of the touch builtin command</p>
<p>[45] [BUG_FIXED] - added the touch buitin command to the executor (i forgot to do)</p>
<p>[46] [NEW_CMD] - rm builtin command init</p>
<p>[47] [LICENSE] - added MIT license to the proj</p>
<p>[48] [MODIFICATION] - modified and changed the README</p>
<p>[49] [NEW_CMD] - wrote wizardsay builtin command</p>
<p>[50] [NEW_FEATURE] - added 'pass' as a new user variable</p>
<p>[51] [NEW_CMD] - wrote 'chpass' command to change password</p>
<p>[52] [NEW_CMD] - wrote 'chuser' command to change username</p>
<p>[53] [NEW_UTIL] - wrote a new helper function to ask for root password and validate it</p>
<p>[54] [MODIFICATION] - allocate memory for 'un' user variable and pass it to the executor</p>
<p>[55] [MODIFICATION] - removed the password validation process from the 'chpass' command and do it in the executor</p>
<p>[56] [MODIFICATION] - did some modification on messages and errors</p>
<p>[57] [NEW_FEATURE] - added switch processing system to the 'ls' builtin command</p>
<p>[58] [NEW_FUNC] - wrote a function to check a ABSS for a specific switch</p>
<p>[59] [NEW_FEATURE] - added useability to switches of the 'ls' builtin command</p>
<p>[60] [NEW_FEATURE] - feature to use 'ls' command on each directory in the current directory</p>
<p>[61] [NEW_FEATURE] - wrote a function to return the file/dir name of joined tokens</p>
<p>[62] [BUG_FIXED] - fixed a bug related to the switch processing</p>
<p>[63] [BUG FIXED] - fixed a bug in 'ls' command that caused segmentation fault error</p>
<p>[64] [BUG FIXED] - fixed the bug that caused inserting garbage characters to the name of the file</p>
<p>[65] [NEW FEATURE] - used 'return_name' helper function to get the file/dir name</p>
