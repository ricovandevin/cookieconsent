<?php

/**
 * @file
 * Contains examples of hook implementations for the Cookie Consent module.
 */

/**
 * Alters the Cookie Consent configuration.
 *
 * @param $config
 *   The current configuration.
 */
function hook_cookieconsent_config_alter(&$config) {
  $config['revokable'] = TRUE;
}

/**
 * Adds JavaScript to the function that is executed when cookies are enabled.
 *
 * @return string
 *   The JavaScript that should be executed when cookies are enabled.
 */
function hook_cookieconsent_enable() {
  return 'console.log("Enabling cookies");';
}

/**
 * Adds JavaScript to the function that is executed when cookies are disabled.
 *
 * @return string
 *   The JavaScript that should be executed when cookies are disabled.
 */
function hook_cookieconsent_disable() {
  return 'console.log("Disabling cookies");';
}
