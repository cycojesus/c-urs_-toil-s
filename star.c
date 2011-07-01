#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* levels have fixed, hardcoded dimensions */
#define LEVEL_HEIGHT 9
#define LEVEL_WIDTH 16

#define WALL '#'
#define BALL '@'
#define CUBE 'H'
#define VOID ' '
#define GIFT '*'

char* levels[] = { "################"
				   "#@##        *#H#"
				   "#          * ###"
				   "#       ##*    #"
				   "#   ## *      ##"
				   "## *  *     *  #"
				   "# *      *## * #"
				   "#     ##*     *#"
				   "################",

				   " #  # # #   # ##"
				   "#   *         @#"
				   "   #*  #*   *   "
				   "# # *     *  # #"
				   "      #   *   # "
				   "#    #H#  *    #"
				   "   #  # #   #**#"
				   "#             # "
				   " #  #        #  ",

				   "################"
				   "#           *#@#"
				   "#   ##      ##H#"
				   "#   #*     *   #"
				   "# *     *##   *#"
				   "# #*  *  *#  *##"
				   "# ##* #*  * *###"
				   "#*    ##*      #"
				   "################",

				   "################"
				   "#            #H#"
				   "#     #        #"
				   "##*#* *#*#*#*#*#"
				   "# # #* *# # # ##"
				   "##*#*#* *#*#*#*#"
				   "#     #        #"
				   "#   #       #@ #"
				   "################",

				   " ############## "
				   "#@  #   #  #   #"
				   "#  #* # *  * # #"
				   "##      #  #   #"
				   "#* #*#        ##"
				   "##     # * #   #"
				   "#*#  # # #   #H#"
				   "#   #    *#  #*#"
				   " ############## ",

				   "    ############"
				   "   #   *   #* *#"
				   "  #    *    # ##"
				   " #     *       #"
				   "#@     *       #"
				   "##     *  #   ##"
				   "#      *    #  #"
				   "#H #   *  ##*  #"
				   "################",

				   "################"
				   "#              #"
				   " ## ###  #* ##*#"
				   " #*  #* # # # # "
				   "  #  #  ### ##  "
				   " ##  #  #*# #*# "
				   "#              #"
				   "#  @#*    H  #*#"
				   "################",

				   "############### "
				   "#  *##        ##"
				   "#  #*  ## *    #"
				   "#  *## # #*    #"
				   "##     ##  #*# #"
				   "## #       *#* #"
				   "#*H*#   *  #@# #"
				   "##             #"
				   " ###############",

				   "  # ########### "
				   " #*#*      #  @#"
				   "#* *#    *    # "
				   " # #  *##  *#  #"
				   "#  #* #*H*    *#"
				   "#     *##     # "
				   "#*#*         #  "
				   "#           #   "
				   "############    ",

				   "    ########### "
				   "#### *         #"
				   "#   H ###* *# *#"
				   "# *   #* #*   # "
				   "#     #  *  # *#"
				   "#*#*  # *#  #@# "
				   " #*   ###  ###  "
				   "#         # # # "
				   " #########  #  #",

				   "################"
				   "#      #      @#"
				   "#  #**     ** ##"
				   "##   *   ##   *#"
				   "#*    #*#**  ###"
				   "## ##    ##    #"
				   "#*  *# *    H *#"
				   "##*###    #   ##"
				   " ## ########### ",

				   "##     ##  #### "
				   "#@#####* ### *##"
				   "#    **     *  #"
				   "# ##  ##*  #*# #"
				   "# # * ###* ##  #"
				   "# ##  ##   #H# #"
				   "#     *        #"
				   "#        *     #"
				   "################",

				   " ############## "
				   "# @#        * ##"
				   "# #   #*   *## #"
				   "#       *    # #"
				   "# *          #*#"
				   "# #      *     #"
				   "##      * *  #*#"
				   "#H  #    * # # #"
				   " ############## ",

				   "################"
				   "#*#*        *#*#"
				   "# *#@      ##  #"
				   "# H        *   #"
				   "#        *#    #"
				   "#      *       #"
				   "# *#        #  #"
				   "#*#*        *#*#"
				   "################",

				   " ###### ####### "
				   "#     *#     * #"
				   "# # * #  #   * #"
				   "#  @#   #** #* #"
				   " # #   # *  H# #"
				   "#*       #  #* #"
				   " #      *     # "
				   "#*            *#"
				   " ############## ",

				   "################"
				   "## H#* *      *#"
				   "#* @*#*       ##"
				   "## ###    *   ##"
				   "##     *#*#    #"
				   "#**       *#*  #"
				   "## *    ####*  #"
				   "##*#  #        #"
				   "################",

				   "################"
				   "# *#        #@ #"
				   "# #  *#**#*  # #"
				   "#    #*##*# *  #"
				   "# *#       *#  #"
				   "#  *#*    *#   #"
				   "# #  # ##*#  # #"
				   "#    * #*   H  #"
				   "################",

				   "################"
				   "# *    *  H#   #"
				   "#  #*#*   #*   #"
				   "#   #*#    #*  #"
				   "#   *  #   *#* #"
				   "# #*#   # *#   #"
				   "# *#* # * #    #"
				   "#*#@  #     #  #"
				   "################",

				   "################"
				   "#*   ##     ##*#"
				   "# #  #      #* #"
				   "# *#   *##  *  #"
				   "# #    #*      #"
				   "#    #   *#    #"
				   "# ## *# ##*  #H#"
				   "# *# #*     ##@#"
				   "################",

				   "################"
				   "#   *#*        #"
				   "##*  *# ##*   ##"
				   "# # # *   #  # #"
				   "# H #  ##  # @*#"
				   "# #  #   * # # #"
				   "##   *## #*  *##"
				   "#        *#*   #"
				   "################",

				   "################"
				   "# ###     *   ##"
				   "#   #       # ##"
				   "#   ##*      * #"
				   "#  *    *   * ##"
				   "#    #    ###* #"
				   "#  * * @ H * **#"
				   "################"
				   "                ",

				   "################"
				   "#*#  #*# #*  # #"
				   "#    #         #"
				   "#*   #  #*  *  #"
				   "## #*      * ###"
				   "# * #   ###*   #"
				   "#     #@#H  *  #"
				   "################"
				   "                ",

				   " ############## "
				   "# #  #*# #*  # #"
				   "#    *  #      #"
				   "##   #   * #*  #"
				   "#  #*  #  ** * #"
				   "##* #   ## *   #"
				   "#     #@#H  *  #"
				   " ############## "
				   "                ",

				   "################"
				   "#     #       ##"
				   "# ##* *    ##*##"
				   "# #*     *#  ###"
				   "# **  *# ##    #"
				   "# #* * #    ## #"
				   "# ##   @#H###**#"
				   "################"
				   "                ",

				   "################"
				   "#            # #"
				   "# * ##*   *    #"
				   "#   #*  *  ##  #"
				   "# *    ##  #*  #"
				   "# #*   *#    * #"
				   "# ##* #@ H     #"
				   "################"
				   "                " };

struct state {
   char level[ LEVEL_HEIGHT * LEVEL_WIDTH ];
   char moving;
   int moves;
};

int count_gifts( struct state *s )
{
   int i, n = 0;
   for( i = 0 ; i < LEVEL_HEIGHT * LEVEL_WIDTH ; i++ ) {
	  if ( s->level[ i ] == GIFT ) {
		 n++;
	  }
   }
   return n;
}

void get_pos( struct state *s, int* pos )
{
   int p;
   
   p = (int)( strchr( s->level, s->moving ) - s->level );

   pos[ 1 ] = p / LEVEL_WIDTH;
   pos[ 0 ] = p - ( pos[ 1 ] * LEVEL_WIDTH );
}

char get_cell( struct state *s, int x, int y )
{
   return s->level[ y * LEVEL_WIDTH + x ];
}

void set_cell( struct state *s, int x, int y, char item )
{
   s->level[ y * LEVEL_WIDTH + x ] = item;
}

void load_level( struct state *s, char* lvl )
{
   strncpy( s->level, lvl, LEVEL_HEIGHT * LEVEL_WIDTH );
   s->moving = BALL;
   s->moves = 0;
}

void switch_actor( struct state *s )
{
   s->moving = (s->moving == BALL) ? CUBE : BALL;
}

int won_or_not( struct state *s )
{
   return( count_gifts( s ) == 0 );
}

void move( struct state *s, int direction )
{
   int dx = 0, dy = 0, tmpx, tmpy, *item_coord;
   item_coord = malloc( sizeof( int ) * 2 );
   get_pos( s, item_coord );
   tmpx = item_coord[ 0 ];
   tmpy = item_coord[ 1 ];
	  
   switch( direction ) {
	  case 'u':
		 dy--;
		 break;
	  case 'd':
		 dy++;
		 break;
	  case 'l':
		 dx--;
		 break;
	  case 'r':
		 dx++;
		 break;
	  default: break;
   }

   /* Calculating arrival coordinates */
   while ( 						/* Hairy conditions ahead */
	  /* target cell is within level's boundaries */
	  ( ( tmpx + dx >= 0 ) && ( tmpx + dx < LEVEL_WIDTH ) ) &&
	  ( ( tmpy + dy >= 0 ) && ( tmpy + dy < LEVEL_HEIGHT ) ) &&
	  /* and target cell is empty */
	  ( get_cell( s, tmpx + dx, tmpy + dy ) == VOID )
	  /* or, in case the ball is moving, target cell can be a gift (which we'll eat) */
	  || ( s->moving == BALL && ( get_cell( s, tmpx + dx, tmpy + dy ) == GIFT ) )
	  ) {
	  tmpx += dx;
	  tmpy += dy;

	  if ( s->moving == BALL && get_cell( s, tmpx, tmpy ) == GIFT ) {
		 set_cell( s, tmpx, tmpy, VOID );
	  }
   }

   /* Moving to arrival coordinates */
   set_cell( s, item_coord[ 0 ], item_coord[ 1 ], VOID );
   set_cell( s, tmpx, tmpy, s->moving );
   
   free( item_coord );
}

void display_level( struct state *s )
{
   int i, j, *ball, *cube;
   
   printf( "%i gifts left", count_gifts( s ) );
   if ( won_or_not( s ) ) {
	  printf( ", You WON !\n");
   }
   else {
	  printf( ", go on.\n");
   }
   
   for( i = 0 ; i < LEVEL_HEIGHT ; i++ ) {
	  for( j = 0 ; j < LEVEL_WIDTH ; j++ ) {
		 switch( get_cell( s, j, i ) ) {
			case WALL:
			   printf( "##" );
			   break;
			case VOID:
			   printf( "  " );
			   break;
			case BALL:
			   printf( "()" );
			   break;
			case CUBE:
			   printf( "[]" );
			   break;
			case GIFT:
			   printf( "<>" );
			   break;
			default: break;
		 }
	  }
	  printf( "\n" );
   }
}

int main( int argc, char* argv[] )
{
   int i = 0;
   struct state *s = malloc( sizeof( struct state ) );
   
   load_level( s, levels[ 0 ] );
   
   display_level( s );

   char* moves = "drdluruldrdlrulurudlurdul";
   do {
   	  fprintf( stderr, "move %c\n", moves[ i ]);
   	  move( s, moves[ i ] );
   	  display_level( s );
   	  i++;
   } while( ( ! won_or_not( s ) ) && ( moves[ i ] != '\0' ) );
   display_level( s );

   free( s );
   return 0;
}
