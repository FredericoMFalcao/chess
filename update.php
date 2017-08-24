<?php
header("Content-type: text/plain");
passthru("GIT_WORK_TREE=/var/www/chessgame GIT_DIR=/var/www/chessgame/.git git pull");
passthru("cd /var/www/chessgame/back-end && make");

