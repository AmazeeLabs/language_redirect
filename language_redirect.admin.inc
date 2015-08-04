<?php

//AXXX
function language_redirect_config_form($form, &$form_state) {
  $languages = language_list();
  $options = array();
  foreach($languages as $lang) {
    $options[$lang->language] = $lang->name;
  }
  $form['language_redirect_temporary_disabled_languages'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Temporary disabled languages'),
    '#description' => t('Select which languages should be temporary disabled for the people who do not have the <em>Access temporary disabled languages</em> permission. They will be redirected to the target language.'),
    '#default_value' => variable_get('language_redirect_temporary_disabled_languages', array()),
    '#options' => $options,
  );
  $form['language_redirect_target_language'] = array(
    '#type' => 'select',
    '#title' => t('Target language'),
    '#default_value' => variable_get('language_redirect_target_language', ''),
    '#options' => $options,
  );
  return system_settings_form($form);
}
