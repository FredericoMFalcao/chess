![Travis CI Badge](https://travis-ci.org/FredericoMFalcao/chess.svg?branch=master)
![](https://api.keen.io/3.0/projects/58c7b2c30935ce7223c4d8b8/events/page_views?api_key=3E921A47984F4CAE2B3839A4251B348377C5BC1887B9AB1CCE4DD3AFC2A1E7AD74ACF3579905EC7487E192A165195725969678879B31EF1222BBB43DDE15C7E1C2FC78E44830CCA7E89D4AA9B1F32F7497816D6F0A22FA1E9E31DB17CA511322&data=eyJwYWdlIjoibWFpbnBhZ2UifQ==)

#  Chess Game with Artifical Intelligence (AI)

This is a simple chess game written in PHP/C to demontrate and test different AI algorithms the computer can use to test its next move. You can test it online; run it on your web server and play in the browser; or compile it and run and play it in the console.

In the browser you can just click on pieces to direct the next move.
In the console you can see type `print` to check the board state and type `move a2 a3` to move pieces.

## Do you want to test it online?

There is an online demo at (http://chessgame.dtdns.net)


## Do you want to Install it?

### Download it with:
`git clone https://github.com/FredericoMFalcao/chess`

### Compile it with:
`make`

### Run it with:
`./chess`


## Code description (per-file):

-  ([index.php](https://github.com/FredericoMFalcao/chess/blob/master/index.php)) Simple board, chess pieces and AJAX methods to communicate board moves

-  ([chess.php](https://github.com/FredericoMFalcao/chess/blob/master/chess.php)) run "chess" back-end.  
	- Convert URL arguments (GET) to console arguments.
	- Print correct server HTTP header (text or JSON)
	- pass correct SESSION string


### Front-end ([/front-end](https://github.com/FredericoMFalcao/chess/tree/master/front-end))

A simple PHP web page displaying the chess board and pieces. The PHP handles sessions.
Javascript generates AJAX calls when 

Check the code documentation [here](https://github.com/FredericoMFalcao/chess/tree/master/front-end)
	
### Back-end ([/back-end](Check the code documentation [here](https://github.com/FredericoMFalcao/chess/tree/master/back-end)))

A C program that can be run independently in a console, i.e. you can play the game just by building and running the file on this folder in the console.

Check the code documentation [here](https://github.com/FredericoMFalcao/chess/tree/master/back-end)
