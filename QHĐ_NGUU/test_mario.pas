program test;
uses crt;
const   N:array['0'..'9'] of integer = (10,20,30,40,50,60,70,200,500,1000);
var a:array[1..1000] of integer;
    S:string;
    i,j,k:longint;
    p:char;
    f:text;
begin
    for p := '7' to '9' do
    Begin
        fillchar(A,sizeof(A),0);
        S := 'test' + p;
        MKDIR(S);
        S := S + '\MARIO.INP';
        assign(f,S); rewrite(f);
        writeln(f,N[p]);
        {K := random(N[p]);
        for i:=1 to K do
        Begin
            j := random(N[p])+1;
            A[j] := random(3);
        end; }
        for i:=1 to N[p] do write(f,A[i],' ');
        close(f);
    end;
end.
