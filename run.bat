set port=8054
start http://localhost:%port% 
title algo - %port%
mkdocs serve -a localhost:%port%
