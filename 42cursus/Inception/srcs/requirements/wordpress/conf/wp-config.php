<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', getenv("DB_NAME") );

/** Database username */
define( 'DB_USER', getenv("DB_USER") );

/** Database password */
define( 'DB_PASSWORD', getenv("DB_PASSWORD") );

/** Database hostname */
define( 'DB_HOST', getenv("DB_HOST") );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'f:uF0Hl%nVqHdwh;>}9$F1#^fS}VK,JNEv(}:H.]T1`(UKcE|2mV6xB009C0&J{(');
define('SECURE_AUTH_KEY',  'LF-8{NJ/V?yc+aQg?/*x{!w7so-aW/*]+:7mIjW!4=<)X:s{#;G*W*; 9PByz$RT');
define('LOGGED_IN_KEY',    'd3X}>pYMV_# b FUF,wIH%|.v<bE.C7^]T`Q-.o2j&^z-bVA{ITsD(IgQTs<Chh6');
define('NONCE_KEY',        'd[e/BsACXvz$o)uZr-ZV5*Z;p!aPLD=~cF:np2@==<86<$ k=+;0r3{C<#d9{fc@');
define('AUTH_SALT',        'V<X2t;KD&`=bN5bR{{h18!2F8Td!>^ey}+-|w?&7<XK!=~^>tp7?- KIX:SO^4}Z');
define('SECURE_AUTH_SALT', ';8$=D+pnc.JW)1v+}1samcI>]C^}SzQ.bAk^YFy/~+w|Sq>xB6 JMVP+{:-qn0WL');
define('LOGGED_IN_SALT',   'Ftu}BxKb5*O5F-u.JE]Hu^QNKX^ViB//L#$DslIOan);Tt-5BouT&n6dNcguEUap');
define('NONCE_SALT',       'S>2UX?6|+j_%2 (<n)`-0p.|k~OR}8ar2?K]zj[9sI<udRru_ySL-L[L^p Lqxac');

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', true );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';