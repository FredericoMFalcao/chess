<?php

passthru("git pull");
passthru("make");

echo "\n HEAD: ";
passthru("git status");

