<?php
header("Content-type: text/plain");
passthru("GIT_WORK_TREE=/var/www/chessgame git pull");
passthru("cd /var/www/chessgame && make");

