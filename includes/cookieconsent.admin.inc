<?php

/**
 * @file
 * Contains cookieconsent.admin.inc.
 */

/**
 * Form definition for the CookieConsent settings form.
 */
function cookieconsent_settings_form($form, &$form_state) {
  $form['palette'] = array(
    '#type' => 'fieldset',
    '#description' => t('Define hex codes for the colors that should be used.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Palette'),
  );

  $form['palette']['cookieconsent_popup_background'] = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'placeholder' => t('# Banner')
    ),
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => variable_get('cookieconsent_popup_background'),
  );

  $form['palette']['cookieconsent_button_background'] = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'placeholder' => t('# Button')
    ),
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => variable_get('cookieconsent_button_background'),
  );

  $form['learn_more_link'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Learn more link'),
  );

  $form['learn_more_link']['cookieconsent_learn_more_type'] = array(
    '#type' => 'radios',
    '#options' => array(
      'default' => t('Link to cookiesandyou.com'),
      'own' => t('Link to your own policy'),
    ),
    '#default_value' => variable_get('cookieconsent_learn_more_type', 'default'),
  );

  $form['learn_more_link']['cookieconsent_learn_more_link'] = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'placeholder' => t('www.example.com/cookiepolicy')
    ),
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => variable_get('cookieconsent_learn_more_link'),
    '#states' => array(
      'visible' => array(
        ':input[name="cookieconsent_learn_more_type"]' => array('value' => 'own'),
      ),
    ),
  );

  $form['cookieconsent_type'] = array(
    '#type' => 'radios',
    '#title' => t('Compliance type'),
    '#options' => array(
      '' => t('Just tell users that we use cookies'),
      'opt-out' => t('Let users opt out of cookies (Advanced)'),
      'opt-in' => t('Ask users to opt into cookies (Advanced)'),
    ),
    '#default_value' => variable_get('cookieconsent_type', ''),
  );

  $form['custom_text'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Custom text'),
  );

  $form['custom_text']['cookieconsent_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#attributes' => array(
      'placeholder' => t('This website uses cookies to ensure you get the best experience on our website.')
    ),
    '#rows' => 2,
    '#default_value' => variable_get('cookieconsent_message'),
  );

  $form['custom_text']['cookieconsent_accept_button_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Accept button text'),
    '#attributes' => array(
      'placeholder' => t('Allow cookies')
    ),
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => variable_get('cookieconsent_accept_button_text'),
    '#states' => array(
      'visible' => array(
        ':input[name="cookieconsent_type"]' => array('value' => 'opt-in'),
      ),
    ),
  );

  $form['custom_text']['cookieconsent_dismiss_button_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Dismiss button text'),
    '#attributes' => array(
      'placeholder' => t('Got it!')
    ),
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => variable_get('cookieconsent_dismiss_button_text'),
  );

  $form['custom_text']['cookieconsent_policy_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Policy link text'),
    '#attributes' => array(
      'placeholder' => t('Learn more')
    ),
    '#maxlength' => 255,
    '#size' => 64,
    '#default_value' => variable_get('cookieconsent_policy_link_text'),
    '#states' => array(
      'visible' => array(
        array(
          ':input[name="cookieconsent_learn_more_type"]' => array('value' => 'default'),
        ),
        array(
          ':input[name="cookieconsent_learn_more_link"]' => array('filled' => TRUE),
        ),
      ),
    ),
  );
  
  return system_settings_form($form);
}
