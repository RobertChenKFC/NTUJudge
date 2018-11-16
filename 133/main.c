#include "source.c"

int main() {
        struct string_count strings[20];
        int i;
        for( i=0 ; i<20 ; i++ )
                strings[i].count = 0;
        compare_and_add( "This", strings );
        compare_and_add( "is", strings );
        compare_and_add( "an", strings );
        compare_and_add( "apple,", strings );
        compare_and_add( "and", strings );
        compare_and_add( "this", strings );
        compare_and_add( "is", strings );
        compare_and_add( "a", strings );
        compare_and_add( "book.", strings );
        sort( strings );
        print( strings );
        return 0;
}
