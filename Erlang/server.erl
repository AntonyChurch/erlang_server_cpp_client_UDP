-module(server).

-export([start/1]).

start(Port) ->
    loop(Port).

loop(Port) ->
    io:format("Looped\n"),
    loop(Port).
