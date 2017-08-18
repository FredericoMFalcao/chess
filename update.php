<?php

passthru("git pull https://fredericomfalcao:4t74ygv6@github.com/FredericoMFalcao/chess.git");
passthru("git pull");
passthru("make");

echo "\n HEAD: ";
passthru("git status");

