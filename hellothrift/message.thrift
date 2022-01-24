namespace go message

struct Data{
    1: string text
}

service format_data {
    Data do_format(1:Data data),
}

struct Req{
    1: string query
}

struct Resp{
    1: i64 code
    2: string message
}

service FormatMsg {
    Resp Query(1:Req req),
}

