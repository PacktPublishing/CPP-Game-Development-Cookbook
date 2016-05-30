/**
 * SlimboxThumbs extensions /rewritten/
 * License: GNU GPL 3.0 or later
 * Contributor(s): Vitaliy Filippov <vitalif@mail.ru>
 */

function makeSlimboxThumbs( $, pathRegexp, wgFullScriptPath ) {
	var re = new RegExp( pathRegexp );
	var reExcl = /(^|\/)skins\//;
	var canview = /\.(jpe?g|jpe|gif|png)$/i;
	var m;
	var names = [];
	// When fitted into the viewport, thumbnail widths are quantized to multiples of this number
	var quant = 80;
	$( 'img' ).each( function( i, e ) {
		if ( e.parentNode.nodeName == 'A' && ( m = re.exec( e.parentNode.href ) ) ) {
			var n = decodeURIComponent( m[1] );
			names.push( n );
		}
	} );
	if ( names.length ) {
		var cb = function( r ) {
			var nodes = [];
			var can;
			var ww = $( window ).width();
			var wh = $( window ).height() * 0.9;
			$( 'img' ).each( function( i, e ) {
				if ( e.parentNode.nodeName == 'A' && ( m = re.exec( e.parentNode.href ) ) && !reExcl.exec( e.src ) ) {
					var n = decodeURIComponent( m[1] );
					if ( !r[n] ) {
						return;
					}
					var h = r[n].url;
					can = canview.exec( n );
					if ( !can || r[n].width > ww || r[n].height > wh ) {
						var sc = Math.floor( ww / quant ) * quant;
						var sh = Math.floor( r[n].width * wh / r[n].height / quant ) * quant;
						if ( sh < sc ) {
							sc = sh;
						}
						if ( r[n].local ) {
							h = wgFullScriptPath + '/thumb.php?f=' + encodeURIComponent( n ) + '&w=' + sc;
						} else {
							h = wgFullScriptPath + '/index.php?action=ajax&rs=efSBTRemoteThumb&rsargs[]=' + encodeURIComponent( n ) + '&rsargs[]=' + sc;
						}
					}
					if ( h != e.src ) {
						var p = $( e.parentNode );
						var c = p.next( '.thumbcaption' );
						if ( !c.length ) {
							c = p.parents( 'li.gallerybox' ).find( '.gallerytext' );
						}
						n = ( c.text().replace( /^\s+|\s+$/g, '' ) || n.replace( /_/g, ' ' ) ) + ' &rarr;';
						e.parentNode._lightbox = [
							h, '<a href="'+e.parentNode.href+'">'+n+'</a>'
						];
						nodes.push( e.parentNode );
					}
				}
			} );
			$( nodes ).slimbox({ captionAnimationDuration: 0 }, function( e, i ) {
				return e._lightbox;
			}, function() { return true; });
		};
		$.ajax({
			url: wgFullScriptPath+'/index.php?action=ajax',
			type: 'POST',
			dataType: 'json',
			data: {
				rs: 'efSBTGetImageSizes',
				'rsargs[]': [ names.join( ':' ) ]
			},
			success: cb
		});
	}
}
