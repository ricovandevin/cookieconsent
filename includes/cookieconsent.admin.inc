<?php

/**
 * @file
 * Contains cookieconsent.admin.inc.
 */

/**
 * Form definition for the CookieConsent settings form.
 */
function cookieconsent_settings_form($form, &$form_state) {
  $form['cookieconsent_minified'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use the minified version (cookieconsent.min.js) of the Cookie Consent javascript plugin'),
    '#description' => t('If you want to be able to debug the javascript (by using cookieconsent.js), uncheck this box.'),
    '#default_value' => variable_get('cookieconsent_minified'),
  );

  $form['cookieconsent_theme'] = array(
    '#type' => 'select',
    '#options' => [
      'none' => t('- None -'),
      'dark-top' => t('Dark Top'),
      'dark-floating' => t('Dark Floating'),
      'dark-bottom' => t('Dark Bottom'),
      'light-floating' => t('Light Floating'),
      'light-top' => t('Light Top'),
      'light-bottom' => t('Light Bottom'),
    ],
    '#title' => t('Choose your theme'),
    '#description' => t('Select the theme you wish to use.'),
    '#default_value' => variable_get('cookieconsent_theme'),
  );

  $form['cookieconsent_theme_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to custom CSS file'),
    '#description' => t('Specify the path to the custom CSS file to use (e.g. <em>themes/[your-theme]/css/cookie-consent.css</em>). This custom CSS file will load only if NO theme is specified above.'),
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => variable_get('cookieconsent_theme_path'),
  );

  $form['texts'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#title' => t('Custom texts'),
  );

  $form['texts']['cookieconsent_customise'] = array(
    '#type' => 'checkbox',
    '#title' => t('Customise the text'),
    '#description' => t('Customise the text used on the cookie bar'),
    '#default_value' => variable_get('cookieconsent_customise'),
  );

  $form['texts']['cookieconsent_headline_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Headline Text'),
    '#description' => t('The message shown by the plugin.'),
    '#rows' => 2,
    '#default_value' => variable_get('cookieconsent_headline_text'),
    '#states' => [
      'visible' => [
        ':input[name="customise"]' => ['checked' => TRUE],
      ],
    ],
  );

  $form['texts']['cookieconsent_accept_button_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Accept button text'),
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => variable_get('cookieconsent_accept_button_text'),
    '#states' => [
      'visible' => [
        ':input[name="customise"]' => ['checked' => TRUE],
      ],
    ],
  );

  $form['texts']['cookieconsent_read_more_button_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Read more button text'),
    '#description' => t('The text shown on the link to the cookie policy (requires the Cookie policy option to also be set)'),
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => variable_get('cookieconsent_read_more_button_text'),
    '#states' => [
      'visible' => [
        ':input[name="customise"]' => ['checked' => TRUE],
      ],
    ],
  );

  $form['cookieconsent_cookie_policy'] = array(
    '#type' => 'entity_autocomplete',
    '#target_type' => 'node',
    '#title' => t('Your cookie policy'),
    '#description' => t('If you already have a cookie policy, link to it here.'),
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => entity_load('node', variable_get('cookieconsent_cookie_policy')),
  );

  $form['cookieconsent_container'] = array(
    '#type' => 'textfield',
    '#title' => t('Container Element'),
    '#description' => t('The element you want the Cookie Consent notification to be appended to. When left empty, the Cookie Consent plugin is appended to the body.'),
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => variable_get('cookieconsent_container'),
  );

  $form['cookieconsent_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path'),
    '#description' => t('The path for the consent cookie that Cookie Consent uses, to remember that users have consented to cookies. Use to limit consent to a specific path within your website.'),
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => variable_get('cookieconsent_path'),
  );

  $form['cookieconsent_expiry'] = array(
    '#type' => 'number',
    '#title' => t('Expiry days'),
    '#description' => t('The number of days Cookie Consent should store the user’s consent information for.'),
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => variable_get('cookieconsent_expiry'),
  );

  $form['cookieconsent_target'] = array(
    '#type' => 'select',
    '#options' => [
      '_blank' => t('_blank (a new window or tab)'),
      '_self' => t('_self (the same frame as it was clicked)'),
      '_parent' => t('_parent (the parent frame)'),
      '_top' => t('_top (the full body of the window)'),
    ],
    '#title' => t('Target'),
    '#description' => t('The <em>target</em> of the link to your cookie policy. Use to open a link in a new window, if you wish.'),
    '#default_value' => !empty(variable_get('cookieconsent_target')) ? variable_get('cookieconsent_target') : '_self',
  );
  
  return system_settings_form($form);
}
