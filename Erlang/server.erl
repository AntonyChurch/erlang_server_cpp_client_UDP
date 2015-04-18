-module(server).

-export([start/1]).

start(Port) ->
  spawn(fun() -> server(Port) end).

server(Port) ->
  {ok, Socket} = gen_udp:open(Port, [binary, {active, false}]),
  io:format("Server opened socket: ~p~n", [Socket]),
  loop(Socket).

loop(Socket) ->
  inet:setopts(Socket, [{active, once}]),
  receive
    {udp, Socket, Host, Port, Bin} ->
      io:format("Server received: ~p~n", [Bin]),
      gen_udp:send(Socket, Host, Port, <<"Thanks for the packet, here is my reply packet!">>),
      loop(Socket)
  end.
